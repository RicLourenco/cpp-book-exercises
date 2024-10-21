/* A vector, which is like an array, is a container to store a bunch of items
contiguously. However, the vector can double its size automatically if we insert a
new item when its capacity has been reached. Also, vectors have many member
functions that arrays don't have, and provide iterators that act like pointers but
aren't */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Initialize a vector
    std::vector<int> vectorList1 = { 35, 41, 94 };

    // Initialize a vector
    std::vector<int> vectorList2;
    vectorList2.push_back(35);
    vectorList2.push_back(41);
    vectorList2.push_back(94);

    // Get item's value based on the index
    int i = vectorList2.at(1);
    int j = vectorList2[0];
    /* However, it is better to always use the at() method instead of the []
    operator when we want to access the specific element by its index in a vector
    instance. This is because, when we accidentally access the out of range
    position, the at() method will throw an out_of_range exception. Otherwise, the
    [] operator will give an undefined behavior */

    /* Another data type that is used when applying a vector is an iterator. This
    is a pointer that is used to point to a specific position of the vector.
    Suppose we are going to insert a new item in the vector. We need to initialize
    the iterator first before we execute the insert() method
    Initialize an iterator */
    std::vector<int>::iterator itr;

    /* To insert a new item in the first position of the vector, we set the
    iterator to the beginning of the vector and then pass it to the insert() method
    Insert an item to the first position */
    itr = vectorList1.begin();
    vectorList1.insert(itr, 58);

    /* We can also insert a new item to the last position of the vector by setting
    the iterator to the end of the vector and then passing it to the insert()
    method as follows:
    Insert an item to the last position */
    itr = vectorList2.end();
    vectorList2.insert(itr, 37);

    /* NOTE: The end() iterator is a past-the-end reference. In other words, trying
    to get the value of *(vectorList.end()) will throw an exception */

    /* And, to insert a new item into the middle of the vector, we can set the
    iterator to point to the beginning of vector, and then we increase the iterator
    to the desired index
    Insert an item to the 4th position */
    itr = vectorList1.begin();
    vectorList1.insert(itr + 3, 67);

    /* To search for the desired element, we can use the find() method provided by
    the vector. However, to use this method, we need to include an algorithm header
    at the beginning of the code file. This method needs three arguments—the first
    position pointer (iterator), the last position pointer (iterator), and the
    value we are going to find. The method will return the position of the found
    item as the iterator. However, if no elements match, the function returns the
    last position iterator
    Search 41 element
    It should be found */
    itr = std::find (vectorList2.begin(), vectorList2.end(), 41);
    if (itr != vectorList2.end())
        std::cout << "Element found in vectorList: " << *itr;
    else
        std::cout << "Element not found in vectorList";
    std::cout << std::endl << std::endl;

    /* The last operation we need is to remove an item from the desired index. We
    can use the erase() method provided by the vector. To use this method, we also
    need to include the algorithm header. Similar to the insert() method, we need
    to find out the beginning of the vector first by using an iterator. We can then
    increment the iterator by as many as the index positions we are going to
    remove
    Remove the 2nd element */
    itr = vectorList1.begin();
    vectorList1.erase(itr + 1);

    return 0;
}