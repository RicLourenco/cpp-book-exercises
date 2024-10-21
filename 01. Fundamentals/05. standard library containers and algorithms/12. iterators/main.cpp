/* iterators are the way in which the position of an element in a container is represented.
an iterator always belongs to a range, the iterator at the beginning of a range can be
accessed with the begin() function while the iterator representing the end, non inclusive,
can be accessed with end(). the range where the first element is included but the last is
excluded is referred to as half-open

an iterator must offer an interface with four functions:
    - the * operator to access the element currently referenced by the iterator
    - the ++ operator used to move forward to the next element
    - the == operator used to compare two iterators to check if they are pointing to the
    same position (two iterators can only be compared if they are part of the same
    range/container)
    - the = operator to assign an iterator

every container class in c++ must specify the type of iterator that it provides to access
its elements as a member type alias named "iterator". for example for a vector of integers
the iterator type would be std::vector<int>::iterator */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = { 1, 2, 3 };
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << "The number is: " << *it << std::endl;
    }

    /* note: the "range-based for" (as seen below) works thanks to iterators. the compiler
    rewrites the below for to look like the above iterator based "for" above */
    for(int number: numbers) {
      std::cout << "The number is: " << number << std::endl;
    }

    return 0;
}

/* iterators can be grouped into four categories, each category builds on the previous
category, thus offering additional functionality:
- input: iterator that can step forward, it can only be used on a single pass
- forward: iterator that can step forward and can be used on multiple passes
- bidirectional: iterator that can step forward and backward
- random-access: iterator that can step forward and backward to arbitrary positions in
in constant time

in more detail:
- input iterator can step forward and allow to read the element it's pointing to. the
iterator can be copied, but when one copy is incremented or dereferenced to access the
element, all the other copies are invalidated and cannot be incremented or dereferenced
anymore. conceptually it means that elements in a sequence that are accessed through an
input iterator can only be read once at most. input iterator are mostly used in patterns
where access to elements is always followed by a position increment. additionally input
iterators provide the == and != operators to check wether the iterator is equal to the
end() value. typically input iterators are used to access elements from a stream of
elements, where the whole sequence isn't stored in memory, but we are obtaining one
element at a time
- forward iterator is very similar to input but provide additional guarantees. the same
iterator can be dereferenced several times to access the element it points to.
additionally when we increment or dereference a forward iterator, the other copies aren't
invalidated: if we make a copy of a forward iterator, we can advance the first one, and
the second one can still be used to access the previous element. two iterators that refer
to the same element are guaranteed to be equal
- bidirectional iterator is also forward iterator with the additional ability to iterate
backwards with the operator --
- random-access iterator is also a bidirectional operator with the additional ability to
directly access any position without the need of a linear scan, in constant time (wut?).
these iterators are provided by the operator [] to access elements at generic indexes and
the binary operators + and - to step forward and backward in any quantity */