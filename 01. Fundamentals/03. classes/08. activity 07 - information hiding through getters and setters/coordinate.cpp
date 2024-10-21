class Coordinate
{
    private:
        float latitude;
        float longitude;

    public:
        float get_latitude() {
            return this -> latitude;
        }
        void set_latitude(float latitude) {
            this -> latitude = latitude;
        }
        float get_longitude() {
            return this -> longitude;
        }
        void set_longitude(float longitude) {
            this -> longitude = longitude;
        } 

};

#include <iostream>

int main()
{
    Coordinate washington_dc;
    std::cout << "Object named washington_dc of type Coordinates created." << "\n";

    washington_dc.set_latitude(38.8951);
    washington_dc.set_longitude(-77.0364);
    std::cout << "Object's latitude and longitude set." << "\n";

    std::cout << "Washington DC has a latitude of "
        << washington_dc.get_latitude()
        << " and longitude of " << washington_dc.get_longitude() << std::endl;
}
