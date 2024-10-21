class Coordinate
{
    public:
        float latitude;
        float longitude;
    
        float distance(const Coordinate& other_coordinate)
        {
            
        }
};

int main()
{
    Coordinate newYorkPosition;
    Coordinate tokyoPosition;

    float newYorkLatitude = newYorkPosition.latitude;
    float distance = newYorkPosition.distance(tokyoPosition);
}