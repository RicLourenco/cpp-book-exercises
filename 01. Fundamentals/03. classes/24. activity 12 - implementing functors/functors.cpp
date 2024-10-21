#include <iostream>

class AddX
{
    private:
        int x;
    public:
        explicit AddX(int x) : x(x) { }

        int operator()(int y) {
            return x + y;
        }
};

int main()
{
    AddX add_five(5);
    std::cout << add_five(4) << std::endl;

    return 0;
}