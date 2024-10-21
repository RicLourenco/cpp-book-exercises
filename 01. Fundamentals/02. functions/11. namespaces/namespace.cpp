#include <iostream>

namespace ex_namespace
{
    // code goes here
    char ch[4] = {'c', 'h', 'a', 'r'};
}

namespace parent
{
    namespace child
    {
        // code goes here
    }
}

int main()
{
    std::cout << ex_namespace::ch;

    return EXIT_SUCCESS;
}