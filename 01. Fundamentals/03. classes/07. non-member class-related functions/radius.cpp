#include <iostream>
#include <string>

class Circle
{
    public:
        int radius;
};

std::ostream& print(std::ostream& os, const Circle& circle) {
    os << "Circle's radius: " << circle.radius;
    return os;
}