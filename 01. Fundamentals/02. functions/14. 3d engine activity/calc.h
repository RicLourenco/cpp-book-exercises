#include <array>

namespace calc
{
    float find_total_distance(std::array<std::array<float, 3>, 6>& points);
    float find_distance(std::array<float, 3>& point1, std::array<float, 3>& point2);
    float find_distance(std::array<float, 3>& point);
    float find_circumference(float radius);
}