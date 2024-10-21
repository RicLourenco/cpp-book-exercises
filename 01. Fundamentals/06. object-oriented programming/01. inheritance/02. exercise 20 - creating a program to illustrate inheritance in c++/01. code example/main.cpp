/* #include <iostream>

// first base class
class Vehicle {
    public:
        int getTankCapacity() {
            const int tankLiters = 10;
            std::cout << "The current tank capacity for your car is "
                << tankLiters << " Liters."<<std::endl;
            return tankLiters;
        }
};

// second base class
class CollectorItem {
    public:
        float getValue() {
            return 100;
        }
};

// Subclass derived from two base classes
class Ferrari250GT: protected Vehicle, public CollectorItem {
    public:
        Ferrari250GT() {
            std::cout << "Thank you for buying the Ferrari 250 GT with tank capacity "
                << getTankCapacity() << std::endl;
            return 0;
        }
};

int main() {
    Ferrari250GT ferrari;
    std::cout << "The value of the Ferrari is " << ferrari.getValue()
        << std::endl;
    // Cannot call ferrari.getTankCapacity() because Ferrari250GT inherits
    // from Vehicle with the protected specifier
    return 0;
}

// Output:
// The current tank capacity for your car is 10 Liters.
// Thank you for buying the Ferrari 250 GT with tank capacity 10
// The value of the Ferrari is 100 */

/* THIS BOOK IS TERRIBLE, THIS WAS THE EXAMPLE CODE THAT IS ACTUALLY WRONG AND DOESN'T
PRINT THE EXPECTED OUTPUT, PLUS THEY RETURN A VALUE INSIDE A CONSTRUCTOR WHICH IS
NOT ALLOWED! */

#include "vehicle.h"

int main()
{
    FerrariGT250GT ferrari;
    std::cout << "The value of the Ferrari is " << ferrari.getValue()
        << std::endl;
    /* cannot call ferrari.getTankCapacity() because Ferrari250GT inherits
    from Vehicle with the protected specifier */

    return 0;
}

/* The specifier is not mandatory. If it is omitted, it defaults to public for
structs and to private for classes

note: If you use inheritance to group together some functionality when implementing
a class, it is often correct to use private inheritance, as that is a detail of how
you are implementing the class, and it is not part the public interface of the class.
If, instead, you want to write a derived class that can be used in place of the base
class, use public inheritance */