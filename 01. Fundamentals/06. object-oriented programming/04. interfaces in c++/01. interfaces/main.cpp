/* An interface is a way for the code to specify a contract that the caller needs
to provide to be able to call some functionality. We looked at an informal
definition when talking about the templates and the requirements they impose on the
types used with them. Functions and methods which accepts parameters as interface
are a way of saying: in order to perform my actions, I need these functionalities;
it's up to you to provide them.

To specify an interface in C++, we can use an Abstract Base Class (ABC). their
names are:
- Abstract: This means that it cannot be instantiated
- Base: This means it is designed to be derived from

Any class that defines a pure virtual method is abstract. A pure virtual method is
a virtual method that ends with = 0 */

class Vehicle
{
    public:
        virtual void turnOn() = 0;
};

/* A pure virtual method is a method that does not have to be defined. Nowhere in
the previous code have we specified the implementation of Vehicle::turnOn().
Because of this, the Vehicle class cannot be instantiated, as we do not have any
code to call for its pure virtual methods. We can instead derive from the class and
override the pure virtual method. If a class derives from an abstract base class,
it can be either of the following:
- Another abstract base class if it declares an additional pure virtual method, or
    if it does not override all the pure virtual methods of the base class
- A regular class if it overrides all the pure virtual methods of the base class */

class GasolineVehicle : public Vehicle
{
    public:
        virtual void fillTank() = 0;
};

class Car : public GasolineVehicle
{
    virtual void turnOn() override { }
    
    virtual void fillTank() override { }
};

/* this makes the GasolineVehicle class also an abstract class like Vehicle, and
Car as the only concrete class and able to be instantiated, as it overrides both
virtual methods declared in the abstract classes. 

abstract classes can't be instantiated but can be referenced and pointed to

Since C++ does not provide a specialized keyword for defining interfaces and
interfaces are simply abstract base classes, there are some guidelines that it's
best practice to follow when designing an interface in C++:
- An abstract base class should not have any data members or fields. The reason for
    this is that an interface specifies behavior, which should be independent of
    the data representation. It derives that abstract base classes should only have
    a default constructor.
- An abstract base class should always define a virtual destructor. The definition
    of a destructor should be the default one: virtual ~Interface() = default. We
    are going to see why it is important for the destructor to be virtual later.
- All the methods of an abstract base class should be pure virtual. The interface
    represents an expected functionality that needs to be implemented; a method
    which is not pure is an implementation. The implementation should be separate
    from the interface.
- All of the methods of an abstract base class should be public. Similar to the
    previous point, we are defining a set of methods that we expect to call. We
    should not limit which classes can call the method only to classes deriving
    from the interface.
- All the methods of an abstract base class should be regarding a single
    functionality. If our code requires multiple functionalities, separate
    interfaces can be created, and the class can derive from all of them. This
    allows us to compose interfaces more easily.
    
Consider disabling the copy and move constructors and assignment operators on the
interface. Allowing the interface to be copied can cause the slicing problem */

int main()
{
    Car redCar;
    Car blueCar;

    Vehicle& redVehicle = redCar;
    Vehicle& blueVehicle = blueCar;
    redVehicle = blueVehicle;
    // problem: object slicing

    /* we only copied the Vehicle part, since the copy constructor of the Vehicle
    class has been called. The copy constructor is not virtual, so the
    implementation in Vehicle is called, and since it only knows about the data
    members of the Vehicle class (which should be none), the ones defined inside
    Car have not been copied! This results in problems that are very hard to
    identify. A possible solution is to disable the interface copy and move
    construct and assign operator: Interface(const Interface&) = delete; and
    similar. This has the drawback of disabling the compiler from creating the copy
    constructor and assign operators of the derived classes. An alternative is to
    declare copy/move constructor/assignment protected so that only derived classes
    can call them, and we don't risk assigning interfaces while using them. */

    return 0;
}

