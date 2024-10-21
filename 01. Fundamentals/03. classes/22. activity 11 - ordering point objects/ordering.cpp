#include <iostream>
#include <string>

class Point
{
    public:
        float x, y;

        Point() { }

        Point(float x, float y) {
            this -> x = x;
            this -> y = y;
        }

        bool operator< (const Point& other) {
            return this -> x < other.x ||
                (this -> x == other.x &&
                this -> y < other.y);
        } 
};

int main()
{
    Point p_1(1, 2), p_2(2, 1), p_3(2, 3), p_4(4, 1), p_5(1, 1), p_6(3, 5), p_7(2, 5), p_8(1, 2);

    Point points[8] = { p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8};
    Point tmp;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (!(points[i] < points[j])) {
                tmp = points[i];
                points[i] = points[j];
                points[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        std::cout << "p_" << i + 1 << "(x: " << points[i].x << ", y: " << points[i].y << ")\n";
    }

    return 0;
}