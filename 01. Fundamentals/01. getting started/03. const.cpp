#include <iostream>

using namespace std;

int main()
{
    const int imm = 10;
    cout << "Immutable constant int: " << imm << "\n";

    int n_imm = 11;
    cout << "Non-immutable int: " << n_imm << "\n";

    constexpr float exp_imm = 4.2;
    cout << "Immutable constant expression float: " << exp_imm << "\n";

    const int &imm_ref = imm;
    cout << "Immutable constant reference: " << imm_ref << "\n";

    //imm = n_imm;
    //compiler error: expression must be a modifiable lvalue

    return 0;
}