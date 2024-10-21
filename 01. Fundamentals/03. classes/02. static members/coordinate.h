class Coordinate
{
    // Data members
    float latitude_ = 0;
    float longitude_ = 0;

    public:
        Coordinate(float latitude, float longitude);

        // Static data member declaration
        static const Coordinate hearthCenter;

        // Member function declaration
        float distanceFrom(Coordinate other);

        // Member function definition
        float distanceFromCenter() {
            return distanceFrom(hearthCenter);
        }
};