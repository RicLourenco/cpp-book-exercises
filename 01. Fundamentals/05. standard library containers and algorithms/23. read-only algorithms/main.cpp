/* read-only algorithms are algorithms that inspect the elements stored inside
a container but do not modify the order of the elements of the container.

the following are the most common operations:
    - all_of, any_of, none_of: these three functions all accept three arguments:
    the beginning of the range, the end, and a unary predicate. they return true
    if the predicate returns true for all, at least one, or no element in the
    sequence, respectively
    - for_each: takes the beginning of a range, the end, and a unary predicate.
    calls the unary predicate with each element in the sequence, in order of
    iteration
    - count, count_if: take the beginning of a range, the end, and a value or a
    unary predicate. returns the number of elements which are equal to value, or
    for which the predicate is true
    - find, find_if, find_if_not: takes the beginning of a range, the end, and a
    value or unary predicate. returns the iterator pointing at the position of
    the first element that is equal to the value, or the end of the range if the
    element isn't found. in the variant with the predicate, it returns the first
    element for which the predicate is true, the end of range otherwise */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vector = { 1, 2, 3, 4 };

    bool allLessThanTen = std::all_of(
        vector.begin(),
        vector.end(),
        [ ] (int value) {
            return value < 10;
        }
    );
    std::cout << "All are less than 10: " << std::boolalpha << allLessThanTen
        << "\n";

    bool someAreEven = std::any_of(
        vector.begin(),
        vector.end(),
        [ ] (int value) {
            return value % 2 == 0;
        }
    );
    std::cout << "Some are even: " << std::boolalpha << someAreEven << "\n";

    bool noneIsNegative = std::none_of(
        vector.begin(),
        vector.end(),
        [ ] (int value) {
            return value < 0;
        }
    );
    std::cout << "None is negative: " << std::boolalpha << noneIsNegative
        << "\n";

    std::cout << "Odd numbers: " << std::count_if(
        vector.begin(),
        vector.end(),
        [ ] (int value) {
            return value % 2 == 1;
        }
    ) << "\n";

    auto position = std::find(vector.begin(), vector.end(), 6);
    std::cout << "6 was found: " << std::boolalpha << (position != vector.end())
        << std::endl;

    return 0;
}