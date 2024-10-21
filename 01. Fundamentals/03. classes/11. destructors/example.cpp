#include <iostream>

class class_name
{
    class_name(); // constructor
    ~class_name(); // destructor
};

class Coordinate
{
    public:
        Coordinate() {
            std::cout << "Constructor called!" << std::endl;
        }

        ~Coordinate() {
            std::cout << "Destructor called!" << std::endl;
        }
};

int main()
{
    Coordinate coordinate;
    return 0;
}