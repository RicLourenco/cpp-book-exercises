#include <iostream>

using namespace std;

int gvar = 1000;

int main()
{
    int gvar = 100;

    cout << "gvar global (outer scope): " << ::gvar << "\n";
    cout << "gvar globar (inner scope): " << gvar << endl;

    return 0;
}