#include "airplane.h"

int main()
{
    Airplane::Airplane airplane1 {
        "Airplane 1"
    };
    airplane1.startTaxi(2, 43);
    airplane1.assignGate(1);
    airplane1.startTaxi(2, 43);
    airplane1.takeOff(304);

    Airplane::Airplane airplane2 {
        "Airplane 2"
    };
    airplane2.startTaxi(3, 21);
    airplane2.takeOff(102);

    return 0;
}