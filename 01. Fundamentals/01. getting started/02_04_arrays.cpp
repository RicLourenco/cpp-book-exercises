#include <iostream>

using namespace std;

int main()
{
    int bi_arr[3][5] = {{ 1, 2, 11, 15, 1989 }, { 0, 7, 1, 5, 19 }, { 9, 6, 131, 1, 2 }};

    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 5; j++) {
            cout << "element at [" << i << "][" << j << "]: " << bi_arr[i][j] << "\n";
        }
    }

    return 0;
}