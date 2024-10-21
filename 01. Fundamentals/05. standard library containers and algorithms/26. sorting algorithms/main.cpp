/* rearranges within a container in a specific order:
    - takes the beginning and end of a range, and optionally a binary predicate. changes
    the order of the range to keep the elements in a sorted, ascending order. when the
    binary predicate is provided, the elements are compared by invoking it, and the first
    argument is moved before the second if it returns true. the < operator is used
    otherwise */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vector = { 5, 2, 6, 4, 3, 1 };

    std::sort(vector.begin(), vector.end());
    std::cout << "Values: ";
    std::for_each(
        vector.begin(),
        vector.end(),
        [](int value) {
            std::cout << value << " ";
        }
    );
    std::cout << std::endl;

    return 0;
}