#include "../../02. Storing Data in Lists and Linked Lists/04. building a singly linked list adt/book's example/Node.h"

template<typename T>
class Stack
{
    private:
        int m_count;
        Node<T> *m_top;

    public:
        Stack();
        bool isEmpty();
        T Top();
        void Push(T val);
        void Pop(); 
};

/* In the Stack data type, we can only get the value of the top node. Thus, the
Top() operation will show the value of the m_top node. The implementation of this
operation is simple */
template<typename T>
T Stack<T>::Top()
{
    return m_top -> Value;
}

/* the operation just returns the value of m_top so that, no matter how many items
there are in Stack, the complexity of this operation is O(1) for both the best case
and worst case scenario. And don't forget to invoke the IsEmpty() method prior to
the invocation of the Top() operation. We should not invoke the Top() operation if
there's no item in Stack since it can cause a run-time error. The IsEmpty() method
itself simply returns FALSE if there's at least one item in Stack; otherwise it
returns TRUE. The implementation of IsEmpty() gives us an O(1) complexity */
template<typename T>
bool Stack<T>::isEmpty()
{
    return m_count <= 0;
}

/* we can only add a new item from the top position of the stack. Since the top
variable in the Stack is similar to Head variable in the LinkedList, we can utilize
the implementation of InsertHead() in the LinkedList data type to be implemented in
the Push() operation in the Stack data type. */
template<typename T>
void Stack<T>::Push(T val)
{
    Node<T> *node = new Node<T>(val);

    // The Next pointer of this new node will point to current m_top node
    node->Next = m_top;

    m_top = node;

    m_count++;
}
/* The preceding code snippet is similar to the implementation of the InsertHead()
operation in the LinkedList data type, except it doesn't have a Tail node. We just
need to create a new node, then link that to the current top node by setting the
Next pointer of the new node to the current top node. Obviously, the complexity of
the Push() operation is O(1) */

/* Again, removing an item in the Stack data type is similar to the RemoveHead()
operation in the LinkedList since we can only access the top node. We simply remove
the first node and make the m_top variable handle the second node */
template<typename T>
void Stack<T>::Pop()
{
    if(isEmpty()) {
        return;
    }

    // Prepare the current m_top to remove
    Node<T> *node = m_top;

    // The new m_top node will be the Next pointer of the current m_top node
    m_top = m_top->Next;

    // Now it's safe to remove the first element
    delete node;

    m_count--;
}
/* Since the Pop() operation in the Stack data type adapts the RemoveHead()
operation in LinkedList, they both have the exact same time complexity, which is
O(1) for best and worst case scenario 

continue on main.cpp... */