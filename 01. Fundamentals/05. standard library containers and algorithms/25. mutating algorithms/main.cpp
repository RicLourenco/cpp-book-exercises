/* mutating algorithms are algorithms that change the order of the elements:
    - reverser, reverse_copy: takes the beginning and end of a range and
    reverses the order of the elements in the two ranges. the reverse_copy
    variant also takes an output iterator and the output of the reversed
    range without modifying the source range
    - shuffle: takes the beginning and end of a range, and a random number
    generator. reorders the elements in the range in a random order */

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> vector = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> reverseVector;

    std::reverse_copy(
        vector.begin(),
        vector.end(),
        std::back_inserter(reverseVector)
    );
    std::cout << "Original elements: ";
    std::for_each(
        vector.begin(),
        vector.end(),
        [ ] (int value) {
            std::cout << value << " ";
        }
    );
    std::cout << "\nReverse elements copy: ";
    std::for_each(
        reverseVector.begin(),
        reverseVector.end(),
        [ ] (int value) {
            std::cout << value << " ";
        }
    );
    std::cout << "\n";

    std::random_device random;
    std::mt19937 rdNumGen(random());
    std::shuffle(vector.begin(), vector.end(), rdNumGen);
    std::cout << "Random values: ";
    std::for_each(
        vector.begin(),
        vector.end(),
        [ ] (int value) {
            std::cout << value << " ";
        }
    );
    std::cout << std::endl;

    return 0;
}