#include <iostream>

class A
{
    friend class B;
    int a = 0;
};

class B
{
    friend class C;
    int b = 0;

    void access_a(const A &object) {
        object.a;
    }
};

class C
{
    int c = 0;

    void access_a(const A &object) {
        object.a;
        // error! A.a is private, and C is not a friend of A
    }
};

int main()
{
    return 0;
}