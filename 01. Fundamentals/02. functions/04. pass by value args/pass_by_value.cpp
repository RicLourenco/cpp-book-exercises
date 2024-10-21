#include <iostream>

using namespace std;

void age_by_value(int age)
{
    age += 5;
    cout << "Age in 5 years: " << age << endl;
    // Prints 100
}

int main()
{
    int age = 95;
    
    age_by_value(age);
    cout << "Current age: " << age << "\n";
    // Prints 95

    return 0;
}