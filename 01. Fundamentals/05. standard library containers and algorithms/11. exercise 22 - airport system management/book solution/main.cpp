#include "airplane.h"

int main()
{
    Airplane airplane(52);
    airplane.currentStatus();
    airplane.startTaxi(12, 250);
    airplane.currentStatus();
    airplane.startTaxi(13, 250);
    airplane.currentStatus();
    airplane.takeOff(800);
    airplane.currentStatus();
    airplane.takeOff(900);

    return 0;
}