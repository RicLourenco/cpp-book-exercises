#include <iostream>

using namespace std;

int gvar = 100;

void print()
{
    cout << "global var: " << gvar << endl;

    //cout << "local var: " << lvar << "\n";
    //compilator error: out of scope
}

int main()
{
    int lvar = 10;
    cout << "local var: " << lvar << "\n";
    cout << "globar var: " << gvar << "\n";

    print();

    return 0;
}