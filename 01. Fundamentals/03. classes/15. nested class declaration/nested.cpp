class Coordinate
{
    public:
        struct CoordinateDistance
        {
            float x = 0;
            float y = 0;
            static float walking_distance(CoordinateDistance distance) {

            }
        };
};

int main()
{
    // create an instance of nested class
    Coordinate::CoordinateDistance distance;

    /* Invoke the static method walkingDistance declared inside
    the nested class CoordinateDistance */
    Coordinate::CoordinateDistance::walking_distance(distance);

    return 0;
}