class Height
{
    double centimeters;

    public:
        Height(double value) : centimeters(value) {

        }
        friend void print_meters(Height);
};