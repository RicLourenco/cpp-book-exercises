/* dyanmic memeory is the part of the memory that the program can use to store
objects, for which the program is responsible for maintaining the appropriate
lifetime. it's also called the heap and is often the alternative to the stack,
which is instead handled automatically by the program. dynamic memeory can usually
store much larger objects than the stack, which usually has a limit.

a program can interact with the operating system to get pieces of dynamic memory
that it can use to store objects, and later it must take care to return such memory
back to the operating system. modern c++ automates most of the memory getting and
returning.

example of dynamic memory: write a function that creates a logger. When we execute
tests, we create a logger specifically for the test called TestLogger, and when we
run our program for users, we want to use a different logger, called
ReleaseLogger.
- We can see a good fit for interfaces here – we can write a logger abstract base
class that defines all the methods needed for logging and have TestLogger and
ReleaseLogger derive from it. All our code will then use a reference to the logger
when logging.
- we cannot create the logger inside the function and then return a reference to
it, since it would be an automatic variable and it would be destructed just after
the return, leaving us with a dangling reference
- we cannot create the logger before calling the function and let the function
initialize it either, since the types are different, and the function knows which
type should be created
- We would need some storage that is valid until we need the logger, to put the
logger in it

given only an interface, we cannot know the size of the classes implementing it,
since multiple classes could implement it and they could have different sizes. This
prevents us from reserving some space in memory and passing a pointer to such space
to the function, so that it could store the logger in it */

#include "logger.h"

class Car { };

int main()
{
    /* in c++ there are two keywords to interact with dynamic memory: "new" and
    "free":

    - the "new" keyword is used to create a new object in dynamic memory */
    Car* car = new Car();
    /* the "new" expression requests a piece of dynamic memory big enough to hold
    the object created, instantiates an object in that memory and returns a pointer
    to that instance. the object pointed to by "car" can now be used until it's
    deleted, with the "delete" keyword followed by the pointer variable, and this
    calls the destructor of the object pointed to, and gives the reserved memory
    back to the operating system */
    delete car;

    // deleting a pointer to an automatic variable will cause an error
    Car car; // automatic variable
    delete &car; // This is an error and will likely crash the program

    /* It is of absolute importance that, for each new expression, we call the
    delete expression only once, with the same returned pointer. by forgetting to
    call the delete function on an object returned by calling the new function, two
    problemas will arise:
    - if this repeatedly happens during the execution of the program, a memory leak
    will occur
    - the destructor of the object will not be called resulting in some resources
    not being returned, for example a database connection would be kept open and
    the db will struggle with too many connections open even though we're only
    using one
    
    another problem arises if we call delete multiple times on the same pointer is
    that all the calls after the first one will access memory they should not be
    accessing, resulting in possible crashes or unexpected behavior by deleting
    other resources the program is using. so it's important to remember: For every
    call to the new operator, there must be exactly one call to delete with the
    pointer returned by new
    
    We can now see why it is extremely important to define a virtual destructor in
    the base class if we derive from it: we need to make sure that the destructor
    of the runtime type is called when calling the delete function on the base
    object. If we call delete on a pointer to the base class while the runtime type
    is the derived class, we will only call the destructor of the base class and
    not fully destruct the derived class. Making the destructor of the base class
    virtual will ensure that we are going to call the derived destructor, since we
    are using dynamic dispatch when calling it.
    
    Like single objects, we can also use dynamic memory to create arrays of
    objects. For such use cases, we can use the new[] and delete[] expressions */
    int n = 15;
    Car* cars = new Car[n];
    delete[] cars;
    /* The new[] expression will create enough space for n Car instances and will
    initialize them, returning a pointer to the first element created. Here, we are
    not providing the arguments to the constructor, so the class must have a
    default constructor. with new[], we can specify how many elements we want it to
    initialize. This is different from std::array and the built-in array we saw
    earlier because n can be decided at runtime.
    
    now with this knowledge, the function to create the logger can be written
    (refer to the "logger.h" header file now)
    
    now this is how to call the function properly */
    Logger* logger = createLogger();
    // some code
    delete logger;
}