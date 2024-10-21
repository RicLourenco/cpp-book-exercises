#include <iostream>
#include <cmath>
#include <array>
#include "calc.h"

const float pi = M_PI;

namespace calc
{

    float calc_distance(float x1, float x2)
    {
        return std::pow(x2 - x1, 2);
    }
    
    float find_distance(std::array<float, 3>& point1, std::array<float, 3>& point2)
    {
        float distance = 0;

        for (short i = 0; i < 3; i++) {
            distance += calc_distance(point1[i], point2[i]);
        }

        float distance_sqrt = std::sqrtf(distance);

        return distance_sqrt;
    }

    float find_distance(std::array<float, 3>& point)
    {
        float distance = 0;

        for (short i = 0; i < 3; i++) {
            distance += calc_distance(point[i], 0);
        }

        float distance_sqrt = std::sqrtf(distance);

        return distance_sqrt;
    }

    float find_total_distance(std::array<std::array<float, 3>, 6>& points)
    {
        float distance = 0;

        for (int i = 1; i < 6; i++) {
            distance += find_distance(points[i - 1], points[i]);
        }

        return distance;
    }

    float find_circumference(float radius)
    {
        return 2 * pi * radius;
    }
}