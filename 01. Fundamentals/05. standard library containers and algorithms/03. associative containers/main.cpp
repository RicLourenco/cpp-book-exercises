#include <iostream>
#include <string>
#include <set>
#include <map>
#include <functional>

// set and multiset
void setAndMultiset()
{
    std::set<int> numbers;
    numbers.insert(10);

    if(numbers.find(10) != numbers.end()) {
        std::cout << "10 is in numbers" << std::endl;
    }

    // example of a set with a custom comparator
    std::set<int> ascending = { 5, 3, 4, 2, 1 };
    std::cout << "ascending numbers:";
    for(int number : ascending) {
        std::cout << " " << number;
    }
    std::cout << std::endl;

    std::set<int, std::greater<int>> descending = { 5, 3, 4, 2, 1 };
    std::cout << "descending numbers:";
    for(int number : descending) {
        std::cout << " " << number;
    }
    std::cout << std::endl;
}

// map and multimap
void mapAndMultimap()
{
    std::map<int, std::string> map;
    map.insert(std::make_pair(1, "some text"));
    auto position = map.find(1);
    if(position != map.end()) {
        std::cout << "Found! the key is " << position -> first
            << ", the value is \"" << position -> second << "\"" << std::endl;
    }

    /* we can access a key/value in a map with the [] operator, but if the
    provided key doesn't exist, it will insert a new key/value pair with 
    that key and a default value (this operator cannot be used on a const
    map because it could modify said map by inserting into it) */
    std::map<int, int> mapInt;
    std::cout << "we ask for a key which does not exist, so it's default inserted: " <<
        map[10] << std::endl;
    map.at(10) += 100;
    std::cout << "now the value is present: " << map.find(10) -> second << std::endl;
}

int main()
{
    setAndMultiset();
    mapAndMultimap();

    return 0;
}