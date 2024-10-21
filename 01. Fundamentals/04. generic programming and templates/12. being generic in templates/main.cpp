/* std::invoke is a function that takes a function as the first argument,
followed by a list of arguments, and calls the function with the arguments */
#include <iostream>
#include <functional>

void do_action(int , float, double) { }

class PrintOnCopyOrMove
{
    public:
        PrintOnCopyOrMove(std::string name) : _name(name) { }
        PrintOnCopyOrMove(const PrintOnCopyOrMove& other) : _name(other._name) {
            std::cout << "Copy: " << _name << std::endl;
        }
        PrintOnCopyOrMove(PrintOnCopyOrMove&& other) : _name(other._name) {
            std::cout << "Move: " << _name << std::endl;
        }

    private:
        std::string _name;
};

void use_printoncopyormove_obj(PrintOnCopyOrMove obj) { }

/* forwarding references:
Forwarding references look like r-value references,
but they only apply where the type is deduced by the compiler */
void do_action2(PrintOnCopyOrMove&&);
// not deduced: r-value reference

template<typename T>
void do_action3(T&&); // deduced by the compiler: forwarding reference

template<typename T>
void do_action4(T&& obj) /* forwarding reference but we can access obj
as if it was a normal l-value reference */ {
    obj.so_something();
    some_function(obj);
}

/* When we are writing templates using a forwarding reference,
we are in front of a dilemma: our type might be a value or a reference,
so how do we decide whether we can use std::move? */
template<typename T>
void do_action5(T&& obj) {
    /* that's why c++ provides a function called std::forward
    Forward looks at the type of T, and if it's an l-value reference,
    then it simply returns a reference to the obj, but if it's not,
    then it is equivalent to calling std::move on the object */
    use_printoncopyormove_obj(std::forward<T>(obj));
    // we are not using obj after this call
}

int main()
{
    double d = 1.5;
    std::invoke(do_action, 1, 1.2f, d);

    PrintOnCopyOrMove local {
        "l-value"
    };
    std::invoke(use_printoncopyormove_obj, local);
    std::invoke(use_printoncopyormove_obj, PrintOnCopyOrMove("r-value"));

    PrintOnCopyOrMove local2 {
        "l-value2"
    };

    do_action5(local2);
    do_action5(PrintOnCopyOrMove("r-value2"));
    do_action5(std::move(local2));
    // we can move because we no longer use local anymore
    /* We successfully managed to write code that is independent
    on whether the type is passed as reference or value,
    removing a possible requirement on the template type parameter */

    return 0;
}