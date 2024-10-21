#include <iostream>
#include "height.h"

void print_meters(Height h) {
    std::cout << "Your height in cm is: " <<  h.centimeters << "cm\n";
    std::cout << "Your height in m is: " << h.centimeters * 0.01 << "m" << std::endl;
}

int main()
{
    Height h(172);
    print_meters(h);

    return 0;
}