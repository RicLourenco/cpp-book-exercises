#include <iostream>

using namespace std;

void modify_ptr(int* ptr)
{
    *ptr = 1;
    ptr = 0;
}

int main()
{
    int a = 0;
    int* ptr = &a;
    modify_ptr(ptr);

    cout << "Value: " << *ptr << "\n";

    // check for myself
    cout << "a: " << a << "\n" << "&a: " << &a << "\n" << "ptr: " << ptr << "\n";

    cout << "Did the pointer change? " << boolalpha << (ptr == &a);

    return 0;
}