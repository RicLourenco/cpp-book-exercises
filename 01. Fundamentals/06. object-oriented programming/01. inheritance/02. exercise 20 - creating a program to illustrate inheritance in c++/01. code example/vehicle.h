#include <iostream>

// first base class
class Vehicle
{
    public:
        int getTankCapacity() {
            return tankLiters;
        }

        void printTankCapacity() {
            std::cout << "The current tank capacity for your car is "
                << tankLiters << " Liters." <<std::endl;
        }

    private:
        const int tankLiters = 10;
};

// second base class
class CollectorItem
{
    public:
        float getValue() {
            return 100;
        }
};

// subclass derived from two base classes
class FerrariGT250GT : protected Vehicle, public CollectorItem
{
    public:
        FerrariGT250GT() {
            std::cout << "Thank you for buying the Ferrari 250 GT with tank capacity "
            << getTankCapacity() << std::endl;
            
            printTankCapacity();
        }
};