#include <iostream>

/* The node is the basic building block of many data structures which we will
discuss in this book. Node has two functions. Its first function is that it holds a
piece of data, also known as the Value of node. The second function is its
connectivity between another node and itself, using an object reference pointer,
also known as the Next pointer. Based on this explanation */

class Node
{
    public:
        int Value;
        Node *Next;
};

void PrintNode(Node *node)
{
    while (node != NULL) {
        std::cout << node -> Value << " -> ";
        node = node -> Next;
    }

    std::cout << "NULL" << std::endl;
}

int main()
{
    Node *node1 = new Node;
    node1 -> Value = 7;

    Node *node2 = new Node;
    node2 -> Value = 14;

    Node *node3 = new Node;
    node3 -> Value = 21;
    /* Note that, since we don't initialize the Next pointer for all nodes, it will
    be automatically filled with the null pointer (NULL)
    
    It's time to connect the preceding three nodes so that it becomes a node chain.
    We will set the Next pointer of node1 to the node2 object, set the Next pointer
    of node2 to the node3 object, and keep the Next pointer of node3 remaining NULL
    to indicate that it's the end of the chain */
    node1 -> Next = node2;
    node2 -> Next = node3;

    PrintNode(node1);

    return 0;
};