#include <iostream>

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
    public:
        T Value;
        Node<T> *Next;

        Node(T value);
};

template <typename T>
Node<T>::Node(T value) : Value(value), Next(NULL) { }

#endif