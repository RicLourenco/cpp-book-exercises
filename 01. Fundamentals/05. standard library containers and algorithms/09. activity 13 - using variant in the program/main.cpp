#include <iostream>
#include <variant>
#include <string>

int main()
{
    std::variant<std::string, int> variant = 42;

    std::cout << std::boolalpha << std::holds_alternative<int>(variant) << "\n";
    std::cout << std::boolalpha << std::holds_alternative<std::string>(variant) << "\n";
    std::cout << std::get<1>(variant) << "\n";
    std::cout << std::get<int>(variant) << std::endl;

    return 0;
}