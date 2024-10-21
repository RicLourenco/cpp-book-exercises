#include <iostream>

class Rectangle
{
    public:
        Rectangle(): width(1), height(2) {

        } // empty function body, as the variables have already been initialized
        int width, height;
};

/* When calling the default constructor of the Example class,
the first method will be initialized first,
and the second method after it,
even if they appear in a different order in the initializer list. */
class Example
{
    public:
    Example(): second(0), first(0) {

    }

    int first;
    int second;
    /* Note
    You should always write the members in the initializer list in the same order as they are declared;
    compilers will help you by warning you when the order differs from the expected one. */
};

/* These types of classes can be initialized, even though they do not have a constructor,
by using a brace-enclosed comma-separated list of initializer-clauses */
struct Rectangle_Struct
{
    int length;
    int width;
};

int main()
{
    Rectangle rectangle;
    std::cout << "Width: " << rectangle.width << std::endl;  // 0
    std::cout << "Height: " << rectangle.height << std::endl; // 0

    // prints: 10, 15
    Rectangle_Struct rectangle_struct = { 10, 15 };
    std::cout << rectangle_struct.length << ", " << rectangle_struct.width << std::endl;
    return 0;
}