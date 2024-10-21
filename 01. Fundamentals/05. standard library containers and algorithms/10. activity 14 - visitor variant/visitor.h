#include <iostream>
#include <string>

namespace visitor
{
    struct Visitor
    {
        void operator()(const std::string& value) {
            std::cout << "a string: " << value << std::endl;
        }

        void operator()(const int& value) {
            std::cout << "an int: " << value << std::endl;
        }
    };
}