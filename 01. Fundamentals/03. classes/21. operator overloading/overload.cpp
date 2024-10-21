#include <iostream>

// overload the + operator
class Point
{
    public:
        Point() { };

        Point(int x, int y) {
            this -> x = x;
            this -> y = y;
        }

        // binary operator, takes one parameter
        Point operator+ (const Point& other) {
            Point new_point;
            new_point.x = x + other.x;
            new_point.y = y + other.y;
            return new_point;
        }

        int x, y;
        bool condition = false;
};

// overloard the ! operator
class ClassOverloadingNotOperator
{
    public:
        // unary operator, takes no parameter
        ClassOverloadingNotOperator& operator!() {
            condition = !condition;
            return *this;
        }

        bool condition = false;
};

int main()
{
    Point first(1, 2), second(2, 4);
    Point sum = first + second;
    // equivalent to
    // sum = first.operator+(second);
    std::cout << "sum x: " << sum.x << ", y: " << sum.y << "\n";

    ClassOverloadingNotOperator object;
    !object;
    // equivalent to
    // object.operator!();
    std::cout << "not ClassOverloadingNotOperator: " << std::boolalpha << object.condition << std::endl;

    return 0;
}