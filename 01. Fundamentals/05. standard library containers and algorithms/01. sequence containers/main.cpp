#include <iostream>
// container's corresponding namespaces
#include <vector>
#include <deque>
#include <list>
#include <forward_list>


void vectorEx()
{
    std::vector<int> myVector;

    myVector.push_back(100);
    // both front and back vector contains a value of 100

    myVector.push_back(10);
    // now, the back of the vector holds 10 as a value, the front holds 100

    myVector.front() -= myVector.back();
    // we subtracted front value with back

    std::cout << "front of the vector: " << myVector.front() << std::endl;
    std::cout << "back of the vector: " << myVector.back() << std::endl;
}

void dequeEx()
{
    /* generally requires more memory than vector, and vector is more performant for
    accessing the elements and push_back so unless insertion at the front is required,
    vector is usually the preferred sequence container */
}

void listEx()
{
    /* list is a data structure of non-adjacent elements that can be dynamically grown
    each element has its memory segment and a link to its predecessor and successor
    (called a node)
    when an element is inserted into the list, the nodes of its predecessor and successor
    need to be updated so they can link to the new object
    similarly if an element is removed, its predecessor and successor need to be updated
    insertion and removal is fast at any position if the node is known by the coder,
    but getting to a specific node is slow */
}

void forwardListEx()
{
    /* similar to list but nodes only have link to successor, so not possible to
    iterate backwards
    only have insert_after and erase_after, for the element after the provided position */
}

// providing initial values to sequence containers
int main()
{
    vectorEx();

    // initialize the vector with 3 numbers
    std::vector<int> numbers = {1, 2, 3};

    return 0;
}