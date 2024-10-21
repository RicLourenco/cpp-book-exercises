/* binary search: takes the beginning and end of a range, a value and an optional binary
predicate. looks for the value in the range and states wether it was found. the provided
range must be sorted according to the binary predicate. if no predicate is provided, it
must be sorted according to the < operator */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vector = { 1, 2, 3, 4, 5, 6 };

    auto found = std::binary_search(vector.begin(), vector.end(), 2);
    std::cout << "Found: " << std::boolalpha << found << std::endl;

    return 0;
}