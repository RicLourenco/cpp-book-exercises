#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> balance;

    balance.insert(std::make_pair("Alice", 50));
    balance.insert(std::make_pair("Bob", 50));
    balance.insert(std::make_pair("Charlie", 50));

    std::string name;
    std::map<std::string, int>::iterator pos;

    do {
        std::cout << "insert the name of the user and press enter" <<
           "\npress enter without inputting a name to exit\n";
        std::getline(std::cin, name);
        pos = balance.find(name);

        if(pos != balance.end()) {
            std::cout << pos -> first << "'s balance is: " << pos -> second << "\n\n";
        } else if(name != "") {
            std::cout << "no user with the name \"" << name << "\" was found\n\n";
        }

    } while (name != "");
    
    

    return 0;
}