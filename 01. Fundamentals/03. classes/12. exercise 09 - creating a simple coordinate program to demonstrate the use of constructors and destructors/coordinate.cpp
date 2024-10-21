#include <iostream>

class Coordinate
{
    private:
        float _latitude;
        float _longitude;

    public:
        Coordinate(float latitude, float longitude) {
            std::cout << "Constructor called!" << std::endl;
            _latitude = latitude;
            _longitude = longitude;
        }

        ~Coordinate() {
            std::cout << "Destructor called!" << std::endl;
        }

        float get_latitude() {
            return _latitude;
        }
        
        float get_longitude() {
            return _longitude;
        }
};

int main()
{
    Coordinate coordinate(3.2342, -6.3432);
    std::cout << "Coordinates latidude: " << coordinate.get_latitude() << "\n";
    std::cout << "longitude: " << coordinate.get_longitude() << std::endl;

    return 0;
}