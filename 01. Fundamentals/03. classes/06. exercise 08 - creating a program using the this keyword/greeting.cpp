#include <iostream>
#include <string>

class Greeting
{
    std::string name;

    public:
        void set_name(const std::string &name) {
            this -> name = name;
        }

        void print_name() {
            std::cout << this -> name << "! Welcome to the C++ community :)" << std::endl;
        }
};

int main()
{
    Greeting greeting;
    greeting.set_name("Ricardo");
    greeting.print_name();

    return EXIT_SUCCESS;
}