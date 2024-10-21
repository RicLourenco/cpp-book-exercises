/* we are going to determine a case of the implementation of an algorithm. There
are three cases when implementing time complexity in an algorithm; they are worst,
average, and best cases. Before we go through them, let's look at the following
Search() function implementation */

int Search(int arr[], int arrSize, int x)
{
    // iterate through the arr elements
    for (int i = 0; i < arrSize; ++i) {
        // if x is found, returns index of x
        if (arr[i] == x) {
            return i;
        }
    }

    // if x isn't found, returns -1
    return -1;
}

/* As we can see in the preceding Search() function, it will find an index of
target element (x) from an arr array containing arrSize elements. Suppose we have
the array {42, 55, 39, 71, 20, 18, 6, 84}. Here are the cases we will find:
    - Worst case analysis is a calculation of the upper bound on the running time
    of the algorithm. In the Search() function, the upper bound can be an element
    that does not appear in the arr, for instance, 60, so it has to iterate through
    all elements of arr and still cannot find the element.
    - Average case analysis is a calculation of all possible inputs on the running
    time of algorithm, including an element that is not present in the arr array.
    - Best case analysis is a calculation of the lower bound on the running time of
    the algorithm. In the Search() function, the lower bound is the first element
    of the arr array, which is 42. When we search for element 42, the function will
    only iterate through the arr array once, so the arrSize doesn't matter. */