#include <iostream>
#include "a.cpp"
#include "b.cpp"

int main()
{
    std::cout << a::default_name << b::default_name;
    return 0;
}

// Note: You should only use anonymous namespaces in cpp files