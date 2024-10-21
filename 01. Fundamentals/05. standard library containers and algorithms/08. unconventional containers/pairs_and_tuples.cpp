/* pair and tuple can store a collection of heterogeneous elements
the pair class can store the values of two types, while the tuple
class extended this concept to any length.
tuple is defined in <tuple> and pair is defined in <utility>. */

#include <iostream>
#include <utility>
#include <tuple>
#include <string>

void pair()
{
    /* the pair constructor takes two template type parameters for
    the first and second values. can be accessed directly using the
    'first' and 'second' data, or get<0>() and get<1>()
    the make_pair() function is used to create a pair without
    explicitly specifying the types */
    std::pair<std::string, int> nameAndAge = std::make_pair("John", 32);

    // these next two lines of code are equivalent
    std::cout << "Name: " << nameAndAge.first << ", age: "
        << nameAndAge.second << std::endl;

    std::cout << "Name: " << std::get<0>(nameAndAge) << ", age: "
        << std::get<1>(nameAndAge) << std::endl;

    /* pairs are used in unordered maps, unordered multimaps, maps,
    and multimap containers to manage their key/value elements */
}

void tuple()
{
    /* the constructor allows to specify a variable amount of template
    arguments. elements are accessed with get<N>(). there is also the
    function make_tuple()
    the tie() function allows the creation of a tuple of references
    which is useful in assigning selected elements from a tuple to
    specific variables */
    std::tuple<std::string, int, float> james =
        std::make_tuple("James", 7, 1.90f);

    std::cout << "Name: " << std::get<0>(james) << ", agent number: "
        << std::get<1>(james) << ", height: " << std::get<2>(james)
        << std::endl;
}

int main()
{
    pair();
    tuple();
    
    return 0;
}