#include <string>

class Car
{
    std::string color;

    void setColorToRed()
    {
        // Explicit use of this
        this -> color = "Red";
    }

    void setColorToBlue()
    {
        // same as this -> color = "Blue"
        color = "Blue";
    }
};