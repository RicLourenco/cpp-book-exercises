#include <iostream>

using namespace std;

void age_by_ref(int& age)
{
    age+=5;
}

int main()
{
    int age = 13;

    age_by_ref(age);

    if (age >= 18) {
        cout << "Happiness!" << endl;
    }

    return 0;
}