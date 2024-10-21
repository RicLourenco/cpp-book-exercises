/* Activity 6: Writing a Math Library for a 3D Game

Johnny wants to implement a math library for the video game he is making.
    It will be a 3D game, so he will need to operate on points representing the three coordinates: x, y, and z.

The points are represented as std::array<float, 3>.
A library will be used throughout the game,
so Johnny needs to be sure it can work when included multiple times
(by creating a header file and declaring the functions there).

The library needs to support the following steps:
    1. Finding the distance between 2 floats, 2 integers, or 2 points.
    2. If only one of the 2 points is provided, the other one is assumed to be the origin (the point at location (0,0,0)).
    3. Additionally, Johnny often needs to compute the circumference of a circle from its radius
    (defined as 2*pi*r) to understand how far enemies can see. pi is constant for the duration
    of the program (which can be declared globally in the .cpp file).
    4. When an enemy moves, it visits several points.
    Johnny needs to compute the total distance that it would take to walk along those points.
    5. For simplicity, we will limit the number of points to 10, but Johnny might need up to 100.
    The function would take std::array<std::array<float, 3>, 10> and compute the distance between consecutive points.

 For example (with a list of 5 points): for the array {{0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {0,1,1}}, the total distance is 5,
because going from {0,0,0} to {1,0,0} is a distance of 1, then going from {1,0,0} to {1,1,0} is a distance of 1 again, and so on for the remaining 3 points.

Make sure that the functions are well-organized by grouping them together.
Remember that the distance between two points is computed as the square root of (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2.
C++ offers the std::pow function for the power function,
which takes the base and the exponent,
and the std::sqrt function, which takes the number to square. Both are in the cmath header. */
#include <iostream>
#include "calc.h"

const float enemy_view_rad = 5;

void init()
{
    std::array<float, 3> enemy1_location = {2, 2 ,0};
    std::array<float, 3> enemy2_location = {2, 4 ,0};
    std::array<std::array<float, 3>, 6> points = { {
        enemy1_location,
        {2,3,0},
        {3,4,1},
        {2,4,2},
        {2,4,1},
        enemy2_location
    } };

    float enemy_distance = calc::find_distance(enemy1_location, enemy2_location);
    float distance_from_center = calc::find_distance(enemy1_location);
    float total_distance = calc::find_total_distance(points);
    float enemy_view = calc::find_circumference(enemy_view_rad);

    std::cout << "enemy 1 is " << distance_from_center << "m away from the center of the map\n";
    std::cout << "enemy 1 and 2 are " << enemy_distance << "m away from each other.\n";
    std::cout << "they can see a circumference of " << enemy_view << "\n";
    std::cout << "with their current trajectories, for the enemies to go from one to another they need to walk: ";
    std::cout << total_distance << "m" << std::endl;
}

int main()
{
    init();
    return EXIT_SUCCESS;
}