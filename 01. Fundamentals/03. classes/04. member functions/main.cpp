#include <string>

class Car
{
    std::string color;

    public:
        void turnOn();
        std::string& getColor() {}
        const std::string& getColor() const {}

    /* The first one is a const member function
    The second returns a const reference
    The third one is a const function that returns a const reference:
    - type& function() const {}
    - const type& function() {}
    - const type& function() const {} */
};

Car car;
// Call std::string& getColor()
// car.getColor();

const Car constCar;
// Call const Color& getColor() const
// constCar.getColor();

void Car::turnOn()
{

}

int main()
{
    return EXIT_SUCCESS;
}