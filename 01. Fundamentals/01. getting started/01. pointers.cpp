#include <iostream>

using namespace std;

int main()
{
    //auto double
    auto var1 = 5.6;
    cout << "val: " << var1 << "\n&val: " << &var1 << "\n\n";

    //auto float
    auto var2 = 5.6f;
    cout << "val2: " << var2 << "\n&val2: " << &var2 << "\n\n";

    //try out pointer
    float *ptr1 = &var2;
    cout << "ptr1: " << ptr1 << "\n&ptr1: " << &ptr1 << "\n\n";

    float var3 = *ptr1;
    cout << "var3: " << var3 <<"\n\n";

    *ptr1 = 4.3;
    cout << "ptr1: " << *ptr1 << endl;
}