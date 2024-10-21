#include "coordinate.h"

Coordinate::Coordinate(float latitude, float longitude)
{
    latitude_ = latitude;
    longitude_ = longitude;
}

const Coordinate Coordinate::hearthCenter = Coordinate(0, 0);