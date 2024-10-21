/* A stack data type is a list with some restriction in the list's operations. It
can only perform the operations from one side, called the top. There are three
basic operations in the Stack data type, and they are Top(), Push(), and Pop(). The
Top() operation is used to fetch the value of the top position item only, the
Push() operation will insert the new item in the top position, and the Pop()
operation will remove the item in the top position. The stack is also known as a
Last In First Out (LIFO) data type. To support these three operations, we will add
one operation to the stack, which is IsEmpty(), to indicate whether the stack has
elements or not. Please take a look at the following stack diagram

In real life, we can imagine that the stack implementation is like when we wear
many bangles on our hand. We put on the bangles one by one on our hand only from
one side. While taking off the bangles, the last bangle we wear is the first bangle
we can remove. Due to this, this is the only time we have access to wearing and
removing the bangles

continue on stack.cpp...

Now, it's time to play with our new Stack data type. We are going to create our
preceding diagram using the Push() operation, and then print the content of the
Stack class using the Pop() operation. To ensure that the stack is not empty, we
are going to use the IsEmpty() operation and we'll use the Top() operation to get
the topmost element to print the value */

#include <iostream>
#include "./stack.h"

int main()
{
    // NULL
    Stack<int> stackInt = Stack<int>();

    return 0;
}