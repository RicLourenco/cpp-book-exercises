/* unique_ptr is a default pointer type. the unique pointer points to an object
that has a single owner; there is a single place in the program that decides when
to delete the object. for example, the logger from before, there is a single place
in the program that decides when to delete it. since we want the logger to be
available as long as the program is running, to always be able to log the
information, we will destroy the logger only at the end of the program.

the unique pointer guarantees the uniqueness of the ownership, the unique pointer
can't be copied. once a unique pointer is created for an object, there can only be
one. when a unique pointer is destroyed, it destroys the object it was pointing to
This way, we have a concrete object that tells us the ownership of the created
object, and we do not have to manually make sure that only one place is calling
delete for the object

a unique pointer takes a single template argument, that being the type of the
object */
#include <memory>
std::unique_ptr<Logger> logger = createLogger();

/* While this code would compile, we would not be respecting the guideline we
mentioned previously regarding always using smart pointers for ownership:
createLogger returns a raw pointer, but it passes ownership to the parent scope. We
can update the signature of createLogger to return a smart pointer */
std::unique_ptr<Logger>createLogger();

/* Now, the signature expresses our intention, and we can update the implementation
to make use of smart pointers. with the use of smart pointers, code bases should not
use new and delete anywhere. This is possible because the standard library, since
C++14, offers a convenient function: std::make_unique. make_unique is a template
function that takes the type of the object to create, and creates it in dynamic
memory, passing its arguments to the object's constructor and returning a unique
pointer to it */
std::unique_ptr<Logger>createLogger() {
    if (tests_are_running()) {
        std::unique_ptr<TestLogger> logger = std::make_unique<TestLogger>();
        return logger; // logger is implicitly moved
    } else {
        std::unique_ptr<ReleaseLogger> logger = std::make_unique<ReleaseLogger>();
        return logger; // logger is implicitly moved
    }
}

/* There are three important points regarding this function:
    - There is no longer a new expression in the body; it has been replaced with
    make_unique. The make_unique function is simple to call because we can provide
    all the arguments we would pass to the constructor of the type and have it
    created automatically.
    - We are creating a unique_ptr to a derived class, but we are returning a
    unique_ptr to a base class. Indeed, unique_ptr emulates the ability of raw
    pointers to convert pointers to derived classes to pointers to base classes.
    This makes using unique_ptr as simple as using raw pointers.
    - We are using the move on the unique_ptr. As we said earlier, we cannot copy
    unique_ptr, but we are returning from a function, so we must use a value;
    otherwise, a reference would become invalid after the function returns

While it cannot be copied, unique_ptr can be moved. When we move unique_ptr, we are
transferring the ownership of the object to which it points to the recipient of the
value. In this case, we are returning value, so we are transferring the ownership
to the caller of the function. Let's now see how we can rewrite the class that owns
the number we showed before */
class A
{
    A(): number(std::make_unique<int>()) { }
    std::unique_ptr<int> number;
};

/* because the unique_ptr deletes the object automatically when it's destroyed,
it's not necessary to write the destructor for the class. If we need to pass a
pointer to the object, without transferring ownership, we can use the get() method
on the raw pointer. Remember that raw pointers should not be used for ownership,
and code accepting the raw pointer should never call delete on it.

Thanks to these features, unique_ptr should be the default choice to keep track of
the ownership of an object */