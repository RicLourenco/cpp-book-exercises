/* remember that the compiler decides how to perform method dispatch based on the
static type of the variable that is used when calling the method. This means that
we need to apply the virtual keyword to the type we are using in the code */

#include <iostream>

class Vehicle
{
    public:
        void turnOn() {
            std::cout << "Vehicle: turn on" << std::endl;
        }
};

class Car : public Vehicle
{
    public:
        virtual void turnOn() {
            std::cout << "Car: turn on" << std::endl;
        }
};

void myTurnOn(Vehicle& vehicle) {
    std::cout << "Calling turnOn() on the vehicle reference" << std::endl;
    vehicle.turnOn();
}

/* the call is not dyanmically dispatched so the call to the implementation of
Vehicle::turnOn() will be executed, because the static type of the variable is
Vehicle and the method wasn't marked as virtual, so the compiler uses static
dispatch. The fact that we wrote a Car class that declares the method virtual is
not important, since the compiler only sees the Vehicle class being used in
myTurnOn(). When a method is declared virtual, we can override it in a derived
class. To override a method, we need to declare it with the same signature as the
parent class: the same return type, name, parameters (including const-ness and
ref-ness), const qualifier, and the other attributes. If the signature does not
match, we will create an overload for the function. The overload will be callable
from the derived class, but it will never be executed with a dynamic dispatch from
a base class */

struct Base
{
    virtual void foo(int) = 0;
};

struct Derived : Base
{
    /* This is an override: we are redefining a virtual method of the base class,
    using the same signature. */
    void foo(int) { }

    /* This is an overload: we are defining a method with the same name of a method
    of the base class, but the signature is different. The rules regarding virtual
    do not apply between Base::foo(int) and Derived:foo(float). */
    void foo(float) { }
};

/* When a class overrides a virtual method of the base class, the method of the
most derived class will be executed when the method is called on a base class. This
is true even if the method is called from inside the base class */

struct A
{
    virtual void foo() {
        std::cout << "A's foo" << std::endl;
    }
};

struct B : A
{
    virtual void foo() override {
        std::cout << "B's foo" << std::endl;
    }

    /* the override enable us to specify that we are overriding a method
    explicitly. This allows the compiler to give us an error message if we use the
    override keyword, but the signature does not match any base class' virtual
    method

    note: Always use the override keyword when you are overriding a method. It is
    easy to change the signature of the base class and forget to update all the
    locations where we overrode the method. If we do not update them, they will
    become a new overload instead of an override! */
};

struct C : B
{
    virtual void foo() override {
        std::cout << "C's foo" << std::endl;
    }
};

int main()
{
    Car car;
    myTurnOn(car);

    B b;
    C c;
    A* a = &b;

    a -> foo(); // B::foo() is executed
    a = &c;
    a -> foo(); /* C::foo() is executed, because it's the most derived Class
    overriding foo(). */

    return 0;
}

/* The virtual keyword can be applied to any method. Since the constructor is not a
method, the constructor cannot be marked as virtual. Additionally, dynamic dispatch
is disabled inside constructors and destructors. While the constructor cannot be
marked as virtual, the destructor can. If a class defines a virtual method, then it
should also declare a virtual destructor. Declaring a destructor virtual is
extremely important when classes are created on dynamic memory, or the heap. We are
going to see later how to manage dynamic memory with classes, but for now, it is
important to know that if a destructor is not declared virtual, then an object
might be only partially destructed */