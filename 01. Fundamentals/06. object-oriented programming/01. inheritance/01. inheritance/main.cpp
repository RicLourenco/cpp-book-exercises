class Vehicle
{
    public:
        TankLevel getTankLevel() const;
        void turnOn();
};

class Transport { };

class Car : public Vehicle, private Transport
/* The visibility modifier specifies who can know about the inheritance relationship
between the classes */
{
    public:
        bool isTrunkOpen();
};

int main()
{
    Car car;
    car.turnOn();

    return 0;
}

/* When the inheritance is public, the code external to the class knows that Car derives
from Vehicle. All the public methods of the base class are accessible as public method
of the derived class by the code in the program. The protected methods of the base class
can be accessed as protected by the methods of the derived class. When inheritance is
protected, all the public and protected members are accessible as protected by the
derived class. Only the derived class and classes that derive from it know about
inheritance; external code sees the two classes as unrelated. Finally, when deriving with
a private modifier, all the public and protected methods and fields of the base class are
accessible by the derived class as private. The private methods and fields of a class are
never accessible outside of that class. Accessing the fields of the base class follows
the same rules */

class Fruit { };

class Citrus : Fruit { };

class Orange : Citrus { };

/* The class Citrus can access the public and protected methods of class Fruit, whereas
class Orange will be able to access both Citrus' and Fruit's public and protected methods
(Fruit's public methods are accessible through Citrus) */