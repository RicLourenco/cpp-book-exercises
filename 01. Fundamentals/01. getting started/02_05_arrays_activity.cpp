#include <iostream>

using namespace std;

int main()
{
    int bi_arr[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            bi_arr[i][j] = i + j;
            cout << "Product of [" << i << "][" << j << "]: " << bi_arr[i][j] << "\n";
        }
    }

    return 0;
}