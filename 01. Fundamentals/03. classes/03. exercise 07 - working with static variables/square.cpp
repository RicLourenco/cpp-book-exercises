#include <iostream>

void square()
{
    static int count = 1, x;
    x = count * count;
    std::cout << count << "² = " << x << "\n";
    count++;
}

int main()
{
    for (short i = 0; i < 10; i++) {
        square();
    }

    return EXIT_SUCCESS;
}