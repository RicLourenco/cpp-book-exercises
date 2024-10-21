#include <iostream>

using namespace std;

//Activity 1: Finding the Factors of 7 between 1 and 100 Using a while Loop
int main()
{
    unsigned short count = 0;
    unsigned short i = 1;

    while (i <= 100) {
        if (i % 7 == 0) {
            count++;
        }

        i++;
    }

    cout << "amount of factors of 7 in range [1-100]: " << count << endl;
}