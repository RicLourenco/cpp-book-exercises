#include <iostream>
#include <vector>

int main()
{
    std::vector<int> balances = { 10, 34, 64, 97, 56, 43, 50, 89, 32, 5 };

    for (auto pos = balances.begin(); pos != balances.end(); ++pos) {
        std::cout << "balance: " << *pos << std::endl;
    }

    return 0;
}