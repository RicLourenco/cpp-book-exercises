#include "../01. refactoring the node<T> data type/doublyNode.h"

template<typename T>
class DoublyLinkedList
{
    private:
        int m_count;

    public:
        // the first node in the list or null if empty
        DoublyNode<T> *Head;

        // the last node in the list or null if empty
        DoublyNode<T> *Tail;

        // constructor
        DoublyLinkedList();

        // get() operation
        DoublyNode<T> *Get(int index);

        // insert() operations
        void InsertHead(T val);
        void InsertTail(T val);
        void Insert(int index, T val);

        // search() operations
        int Search(T val);

        // remove() operations
        void RemoveHead();
        void RemoveTail();
        void Remove(int index);

        // additional operations
        int Count();
        void PrintList();
        void PrintListBackwards();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : m_count(0), Head(NULL), Tail(NULL) { }

/* As we discussed earlier, in the DoublyLinkedList, we can have O(1) for the
complexity of the RemoveTail() operation. This can happen now since we have the
Previous pointer in each element. To do so, we just need to pick the current Tail
node and then assign the previous node of the current Tail as the new Tail. After
that, we can safely remove the last element */
template<typename T>
void DoublyLinkedList<T>::RemoveTail()
{
    if (m_count == 0) {
        return;
    }

    if (m_count == 1) {
        RemoveHead();
        return;
    }

    DoublyNode<T> *node = Tail;
    Tail = Tail->Previous;
    Tail->Next = NULL;
    delete node;
    m_count--;
}

/* For the RemoveHead() operation, the Previous pointer of the new Head must point
to NULL */
template<typename T>
void DoublyLinkedList<T>::RemoveHead()
{
    if (m_count == 0) {
        return;
    }

    DoublyNode<T> *node = Head;
    Head = Head->Next;
    delete node;

    if (Head != NULL) {
        Head->Previous = NULL;
    }

    m_count--;
}

/* or the Remove() operation, when we link the two nodes between the removed node,
we also need to point to the Previous pointer of the right element to the left
element */
template<typename T>
void DoublyLinkedList<T>::Remove(int index)
{
    if (m_count == 0) {
        return;
    }

    if (index < 0 || index >= m_count) {
        return;
    }

    if (index == 0) {
        RemoveHead();
        return;
    } else if (index == m_count - 1) {
        RemoveTail();
        return;
    }

    DoublyNode<T> *prevNode = Head;
    for (int i = 0; i < index; i++) {
        prevNode = prevNode->Next;
    }

    DoublyNode<T> *node = prevNode->Next;
    DoublyNode<T> *nextNode = node->Next;
    prevNode->Next = nextNode;
    nextNode->Previous = prevNode;
    delete node;

    m_count--;
}

/* Due to the existence of the Previous pointer, we also need to refactor the
inserting operation in the LinkedList data type. For the InsertHead() operation,
the Previous pointer of the former Head must point to the new Head */
template<typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
    DoublyNode<T> *node = new DoublyNode<T>(val);
    node->Next = Head;

    if (Head != NULL) {
        Head->Previous = node;
    }

    Head = node;

    if(m_count == 0) {
        Tail = Head;
    }

    m_count++;
}

/* For the InsertTail() operation, we need to point the Previous pointer of the new
Tail to the node before it */
template<typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
    if (m_count == 0) {
        InsertHead(val);
        return;
    }

    DoublyNode<T> *node = new DoublyNode<T>(val);
    Tail->Next = node;
    node->Previous = Tail;
    Tail = node;

    m_count++;
}

/* For the Insert() operation, we need to point the Previous pointer of the node
after the new element to this new element. Also, the Previous pointer of the new
node points to the node before this new node */
template<typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
    if (index < 0 || index > m_count) {
        return;
    }

    if (index == 0) {
        InsertHead(val);
        return;
    }

    if (index == m_count) {
        InsertTail(val);
        return;
    }

    DoublyNode<T> *prevNode = Head;

    for (int i = 0; i < index - 1; i++) {
        prevNode = prevNode->Next; 
    }

    DoublyNode<T> *nextNode = prevNode->Next;
    DoublyNode<T> *node = new DoublyNode<T>(val);
    node->Next = nextNode;
    node->Previous = prevNode;
    prevNode->Next = node;
    nextNode->Previous = node;

    m_count++;
}

template<typename T>
DoublyNode<T> *DoublyLinkedList<T>::Get(int index)
{
    if (index < 0 || index > m_count) {
        return NULL;
    }

    DoublyNode<T> *node = Head;

    for (int i = 0; i < index; ++i) {
        node = node->Next;
    }

    return node;
}

template<typename T>
int DoublyLinkedList<T>::Search(T val)
{
    if (m_count == 0) {
        return -1;
    }

    int index = 0;

    DoublyNode<T> *node = Head;

    while (node->Value != val) {
        index++;
        node = node->Next;

        if (node == NULL) {
            return -1;
        }
    }

    return index;
}

template<typename T>
int DoublyLinkedList<T>::Count()
{
    return m_count;
}

template<typename T>
void DoublyLinkedList<T>::PrintList()
{
    DoublyNode<T> *node = Head;

    while (node != NULL) {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }

    std::cout << "NULL" << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::PrintListBackwards()
{
    DoublyNode<T> *node = Tail;

    while (node != NULL) {
        std::cout << node->Value << " -> ";
        node = node->Previous;
    }

    std::cout << "NULL" << std::endl;
}