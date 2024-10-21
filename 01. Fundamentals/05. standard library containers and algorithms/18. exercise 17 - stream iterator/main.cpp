#include <iostream>
#include <iterator>

int main()
{
    std::istream_iterator<int> it = std::istream_iterator<int>(std::cin);
    std::istream_iterator<int> end;
    for (; it != end; ++it) {
        std::cout << "The number is " << *it << std::endl;
    }

    return 0;
}