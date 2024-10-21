#include <iostream>

using namespace std;

int main()
{
    int var1 = 2;
    int &ref1 = var1;

    cout << "var1: " << var1 << "\n";
    cout << "ref1: " << ref1 << "\n\n";

    ref1 = 3;

    cout << "var1: " << var1 << "\n";
    cout << "ref1: " << ref1 << "\n\n";

    var1 = 4;

    cout << "var1: " << var1 << "\n";
    cout << "ref1: " << ref1 << "\n\n";
}