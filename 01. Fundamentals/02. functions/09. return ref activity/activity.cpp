/* In this activity, we are going to see the different trade-offs
that can be made when writing a function,
depending on the parameters the function accepts:

1. Write a function that takes two numbers and returns the sum.
Should it take the arguments by value or reference?
Should it return by value or by reference?

2. After that, write a function that takes two std::arrays
of ten integers and an index(guaranteed to be less than 10) and returns the greater of the
two elements to the given index in the two arrays.

2.1. Now take the previous function we created:
The calling function should then modify the element.
Should it take the arguments by value or reference?
Should it return by value or by reference?
What happens if the values are the same?

Take the arrays by reference and return by reference because we are saying that the
calling function is supposed to modify the element.
Take the index by value since there is no reason to use references.

If the values are the same, the element from the first array is returned. */

#include <iostream>
#include <array>

using namespace std;

// my answers

/* 1. should receive args by reference because it's unnecessary to allocate two more memory blocks
when we can just access the values inside the already existing mem blocks
and should return a value because if not, after the function is passed its lifetime
the value in the mem block of said sum will be invalid and consequently the compiler will be allocating
a value from an invalid block into another integer outside this function */
int sum_a(int& num1, int& num2)
{
    int num3 = num1 + num2;
    return num3;
}

/* 2. */
int greater(array<int, 10> arr1, array<int, 10> arr2, int index)
{
    if(arr1[index] >= arr2[index]) {
        return arr1[index];
    } else {
        return arr2[index];
    }
}

/* 2.1.
???? */


// answers

/* 1. incorrect
take by value, return by value, since the types are small
in memory and there is no reason to use references. */
int sum(int a, int b)
{
    return a + b;
}

/* 2. correct */

/* 2.1.
now the function should return a reference and receive references to both arrays
since now we know that the calling function will use the returned element later;
also this function should return the element from the first array should the
values be the same */
int& getMaxOf(std::array<int, 10>& array1, std::array<int, 10>& array2, int index)
{
    if (array1[index] >= array2[index]) {
        return array1[index];
    } else {
        return array2[index];
    }
}


int main()
{   
    return EXIT_SUCCESS;
}