#include <iostream>

struct Square
{
    int height;
};

// implicit constructor
struct Rectangle
{
    int height, width;

    Rectangle() {
        height = 0;
        width = 0;
    }
    Rectangle(Square square) {
        height = square.height;
        width = 0;
    }
    void use_rectangle(Rectangle rectangle) {

    }
};

// explicit constructor
struct Explicit_Rectangle
{
    Explicit_Rectangle();

    explicit Explicit_Rectangle(Square square) {

    }

    void use_explicit_rectangle(Explicit_Rectangle rectangle) {

    }
};

int main()
{
    Rectangle rectangle;
    // What will the following print function print?
    std::cout << "Rectangle height: " << rectangle.height << std::endl;

    Square square;
    square.height = 3;

    Rectangle rectangle_2(square);

    std::cout << "Rectangle 2 height: " << rectangle_2.height << "\nwidth: " << rectangle_2.width << std::endl;

    /* with the implicit constructor, this is possible, the compiler creates
    a rectangle object by calling the constructor that accepts a square */ 
    rectangle.use_rectangle(square);

    // with the explicit constructor, the previous doesn't work
    Explicit_Rectangle explicit_rectangle;
    explicit_rectangle.use_explicit_rectangle(square);

    return EXIT_SUCCESS;
}