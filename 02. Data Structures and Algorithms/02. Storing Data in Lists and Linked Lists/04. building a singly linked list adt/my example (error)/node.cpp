#include <iostream>
#include "node.h"

template <typename T>
Node<T>::Node(T value) : Value(value), Next(NULL) { }