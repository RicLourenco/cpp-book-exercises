#include <iostream>

using namespace std;

int main()
{
    unsigned short count = 0;

    for (unsigned short i = 1; i <= 30 ; i++) {
        if (i % 3 == 0) {
            count++;
        }
    }

    cout << "divisible by 3 in range [1-30]: " << count << "\n";

    count = 0;

    for (unsigned short i = 1; i <= 100; i++) {
        if(i % 11 == 0) {
            count++;
        }
    }

    cout << "divisible by 11 in range [1-100]: " << count << "\n";

    count = 0;

    for (unsigned short i = 1; i <= 30; i++) {
        if(i % 3 != 0) {
            count++;
        }
    }

    cout << "non divisible by 3 in range [1-30]: " << count << endl;

    return 0;
}