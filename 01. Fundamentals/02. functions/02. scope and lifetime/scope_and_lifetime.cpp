#include <iostream>

using namespace std;

/* 1 */ const int globalVar = 10;

int* foo(const int* other)
{
    /* 5 */ int fooLocal = 0;
    cout << "foo's local: " << fooLocal << endl;
    cout << "main's local: " << *other << endl;

    /* 6 */ return &fooLocal;
}

int main()
{
    /* 2 */ int mainLocal = 15;
    /* 3 */ int* fooPointer = foo(&mainLocal);

    cout << "main's local: " << mainLocal << endl;
    cout << "We should not access the content of fooPointer! It's not valid." << endl;

    /* 4 */ return 0;
}