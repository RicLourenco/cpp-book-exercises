#include <iostream>
#include <optional>
#include <string>
#include <variant>

namespace Airplane
{
    struct AtGate
    {
        std::optional<int> gate;
    };

    struct Taxi
    {
        std::optional<int> lane;
        std::optional<int> numPassengers;
    };

    struct Flying
    {
        std::optional<float> speed;
    };

    struct Airplane
    {
        std::string name;
        AtGate atGate;
        Taxi taxi;
        Flying flying;
        std::variant<AtGate, Taxi, Flying> state;

        void assignGate(int gateNumber) {
            atGate.gate = gateNumber;
            state = atGate;
        }
        
        void startTaxi(int lane, int numPassengers) {
            if (not atGate.gate.has_value() || not std::holds_alternative<AtGate>(state)) {
                currentStatus("The taxi couldn't be started because the gate isn't assigned");
            } else {
                taxi.lane = lane;
                taxi.numPassengers = numPassengers;
                currentStatus("The taxi started on gate " + std::to_string(atGate.gate.value())
                + ", on lane " + std::to_string(taxi.lane.value()) + " with "
                + std::to_string(taxi.numPassengers.value()) + " passengers");
                state = taxi;
            }
        }

        void takeOff(float speedInKmh) {
            if (not std::holds_alternative<Taxi>(state)) {
                currentStatus("The plane couldn't take off because it's not in the taxi state");
            } else {
                flying.speed = speedInKmh;
                currentStatus("The plane took off at " + std::to_string(flying.speed.value())
                + "KM per Hour");
                state = flying;
            }
        }

        void currentStatus(std::string status) {
            std::cout << name << " state: " << status << std::endl;
        }
    };
}