/* iterators being tightly tied with containers means that when there are changes
to the container that might move elements, iterators pointing to such elements
can no longer be used, they are invalidated. it's extremely important to always
check the invalidation contract when using iterators, as it's not specified what
happens with an invalidated container. commonly, invalid data is accessed or the
program crashes. it's more easy to remember when an iterator is invalidated when
taking into account how containers are implemented, for example when inserting an
element into a vector, we might have to get more memory to store the new elements,
in which case the previous elements are moved to the newly obtained memory,
invalidating the iterators that are now pointing to the old memory location. on
the other hand, when inserting a new element into a list, only the predecessor and
successor nodes are updated but the elements are not moved and the iterators
remain valid */

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vector = { 1 };
    auto first_in_vec = vector.begin();
    std::cout << "before vector insert: " << *first_in_vec << "\n";
    vector.push_back(2);

    // first iterator is now invalid, we can no longer use it
    std::cout << "after vector insert: " << *first_in_vec << "\n";

    std::list<int> list = { 1 };
    auto first_in_list = list.begin();
    std::cout << "before list insert: " << *first_in_list << "\n";
    list.push_back(2);
    std::cout << "after list insert: " << *first_in_list << std::endl;

    return 0;
}

/* when there is need to store iterators to elements, iterator invalidation is an
important consideration to make when choosing which container to use */