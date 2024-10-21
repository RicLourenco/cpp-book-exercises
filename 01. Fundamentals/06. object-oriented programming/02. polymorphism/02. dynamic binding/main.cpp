/* Dynamic binding is the ability for a reference or a pointer of a base type to
point to an object of a derived type at runtime */

struct A { };

struct B : A { };

struct C : A { };

class Vehicle
{
    public:
        float getFuelInTank() {
            return 1;
        }

        bool batteryHasEnergy() {
            return true;
        }

        void turnOn() { }
};

class Truck : public Vehicle { };

class Car : public Vehicle { };

void safeTurnOn(Vehicle& vehicle) {
    if (vehicle.getFuelInTank() > 0.1 && vehicle.batteryHasEnergy()) {
        vehicle.turnOn();
    }
}

int main()
{
    // we can write
    B b;
    C c;

    A& ref1 = b;
    A& ref2 = c;
    A* ptr = nullptr;

    if(runtime_condition()) {
        ptr = &b;
    } else {
        ptr = &c;
    }

    /* note: To allow dynamic binding, the code must know that the derived class
    derives from the base class. If the inheritance's visibility is private, then
    only code inside the derived class will be able to bind the object to a
    pointer or reference of the base class. If the inheritance is protected, then
    the derived class and every class deriving from it will be able to perform
    dynamic binding. Finally, if the inheritance is public, the dynamic binding
    will always be allowed

    this creates the distinction between the static type: the type that appears in
    the source code; and the dynamic type: the real type of the object. in this
    case we can see that the static type of both ref1 and ref2 is a reference to A,
    but the dynamic type is B and C respectively because they refer to locations
    in memory where objects of type B and C are stored */

    ptr = &b; // ptr dynamic type is B
    ptr = &c; // ptr dynamic type is now C

    /* It is important to understand that only references and pointers can be
    assigned values from a derived class safely. If we were to assign an object to
    a value type, we would get a surprising result – the object would get sliced */

    B b;
    A a = b;

    /* The code would compile, but only the embedded part of A inside of B would be
    copied - when we declare a variable of type A, the compiler dedicates an area
    of the memory big enough to contain an object of type A, so there cannot be
    enough space for B. When this happens, we say that we sliced the object, as we
    took only a part of the object when assigning or copying
    
    this happens because c++ uses static dispatch by default: when the compiler sees
    a method call, it will check the static type of the variable on which the method
    is called, and it will execute the respective implementation. In case of
    slicing, the copy constructor or assignment operator of A is called, and it only
    copies the part of A inside B, ignoring the remaining fields

    C++ supports dynamic dispatch. This is done by marking a method with a special
    keyword: virtual. If a method is marked with the virtual keyword, when the
    method is called on a reference or a pointer, the compiler will execute the
    implementation of the dynamic type instead of the static type */

    Car car;
    Truck truck;

    safeTurnOn(car);
    safeTurnOn(truck);

    /* A typical pattern is to create an interface that only specifies the methods
    that are required for some functionality. Classes that need to be used with such
    functionality must derive the interface and implement all the required methods */

    return 0;
}