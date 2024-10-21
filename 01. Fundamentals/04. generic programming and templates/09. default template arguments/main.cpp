#include <iostream>

// we can declare default template args like in functions
template<typename T = int>
void foo();

/* default args have to come after args without default values,
we can reference previous args in the default args, examples: */
// wrong
template<typename T = void, typename A>
void foo();
// wrong
template<typename T = A, typename A = void>
void foo();
// correct
template<typename T, typename A = T>
void foo();

template<typename T>
struct Less
{
    bool operator()(const T& a, const T& b) {
        return a < b;
    }
};
template<typename T, typename Comparator = Less<T>>
class SortedArray
{
    // something
};

// example of default non-type parameter
template<size_t Size = 512>
struct MemoryBuffer
{
    // something
};

int main()
{
    //implementation of the hypothetical SortedArray class
    SortedArray<int> sortedArray1;
    SortedArray<int, std::greater<int>> sortedArray2;

    MemoryBuffer buffer1;
    MemoryBuffer<1024> buffer2;

    return 0;
}