/* The Doubly Linked List is almost the same as the Singly Linked List, except the
Node used by Doubly Linked List has a Previous pointer instead of only having the
Next pointer. The existence of the Previous pointer will make the Doubly Linked
List possible to move backwards from Tail to Head. As a result, we can reduce the
complexity of the RemoveTail() operation to O(1) instead of O(N), like we have in
the Singly Linked List data type */

#include "./02. refactoring several operations the linked list adt/doublyLinkedList.h"

int main()
{
    // NULL
    DoublyLinkedList<int> doublyLinkedList = DoublyLinkedList<int>();

    // it will be printed backwardly
    // 43->NULL
    doublyLinkedList.InsertHead(43);

    // 43->76->NULL
    doublyLinkedList.InsertHead(76);

    // 15->43->76->NULL
    doublyLinkedList.InsertTail(15);

    // 44->15->43->76->NULL
    doublyLinkedList.InsertTail(44);

    // Print the list element
    std::cout << "First Printed:" << std::endl;
    doublyLinkedList.PrintListBackwards();
    std::cout << std::endl;

    // 100->44->15->43->76->NULL
    doublyLinkedList.Insert(4, 100);

    // 100->44->48->15->43->76->NULL
    doublyLinkedList.Insert(3, 48);

    // 100->44->48->15->43->76->22->NULL
    doublyLinkedList.Insert(0, 22);
    
    // Print the list element
    std::cout << "Second Printed:" << std::endl;
    doublyLinkedList.PrintListBackwards();
    std::cout << std::endl;

    return 0;
}