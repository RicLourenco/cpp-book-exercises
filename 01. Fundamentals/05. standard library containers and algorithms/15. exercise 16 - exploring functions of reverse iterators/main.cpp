#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << "the numbers is: " << *rit << std::endl;
    }
    
    return 0;
}