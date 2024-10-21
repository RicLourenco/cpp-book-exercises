/* modifying algorithms are algorithms that modify the collection they iterate on:
    - copy, copy_if: take the beginning of a range, the end, and an output
    iterator. copies the elements in the range into the output iterator. the
    copy_if variant additionally takes a unary predicate and copies the element
    only if the predicate is true
    - transform: there are two overloads of the function. one takes the beggining
    and end of a range, an putput iterator and a unary predicate. it applies the
    unary predicate to each element in the range and outputs them into the output
    iterator. the second one takes the beginning and end of a range, the beginning
    of a second range which needs to be at least as long as the first one, an
    output iterator and a binary predicate. it applies the binary predicate,
    passing the elements at the same position in the two ranges, and outputs the
    returned value into the output iterator
    - remove, remove_if: takes the beginning and end of a range, and a value or
    unary predicate. the algorithm doesn't actually remove elements from a
    container, but it puts all the elements equal to a value or for which the
    predicate is true, at the end of the container, and returns the iterator after
    the last elements that shouldn't be removed. the iterator can't know how to
    remove elements, since the algorithm isn't provided with iterators, so it
    groups them to make it easier to remove by calling the appropriate method in
    the container */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<std::string> vector = { "Hello", "C++", "Morning", "Learning" };
    std::vector<std::string> longWords;
    std::copy_if(
        vector.begin(),
        vector.end(),
        std::back_inserter(longWords),
        [ ] (const std::string& s) {
            return s.length() > 3;
        }
    );
    std::cout << "Number of words with more than 3 character: " << longWords.size()
        << "\n";

    std::vector<int> lengths;
    std::transform(
        longWords.begin(),
        longWords.end(),
        std::back_inserter(lengths),
        [ ] (const std::string& s) {
            return s.length();
        }
    );
    std::cout << "Lengths: ";
    std::for_each(
        lengths.begin(),
        lengths.end(),
        [ ] (int length) {
            std::cout << length << " ";
        }
    );
    std::cout << "\n";

    auto newLast = std::remove_if(
        lengths.begin(),
        lengths.end(),
        [ ] (int length) {
            return length < 7;
        }
    );
    std::cout << "No elements removed yet: " << lengths.size() << "\n";

    // erase all elements between two iterators
    lengths.erase(newLast, lengths.end());
    std::cout << "Elements are removed now. Content: ";
    std::for_each(
        lengths.begin(),
        lengths.end(),
        [ ] (int length) {
            std::cout << length << " ";
        }
    );
    std::cout << std::endl;

    return 0;
}