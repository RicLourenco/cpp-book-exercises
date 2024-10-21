#include <iostream>

using namespace std;

void age_by_ref(int& age)
{
    if (age >= 18) {
        cout << "Congratulations! You are eligible to vote for your nation." << endl;
        return;
    }
    else {
        int reqAge = 18;
        int yearsToGo = reqAge - age;
        cout << "No worries, just " << yearsToGo << " more years to go!";
    }
}

int main()
{
    int age;
    cout << "Please enter your age: ";
    cin >> age;

    age_by_ref(age);

    return 0;
}