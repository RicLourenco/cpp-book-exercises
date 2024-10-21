#include <iostream>

using namespace std;

namespace LamborghiniCar
{
    /* void output()
    {
        cout << "Congratulations! You deserve the Lamborghini." << endl;
    } */

    string output()
    {
        return "Congratulations! You deserve the Lamborghini.";
    }
}

namespace PorscheCar
{
    /* void output()
    {
        cout << "Congratulations! You deserve the Porsche." << endl;
    } */

    string output()
    {
        return "Congratulations! You deserve the Porsche.";
    }
}

int main()
{
    int magicNumber;
    cout << "Please input a number between 1 and 2: ";
    cin >> magicNumber;

    if (magicNumber == 1) {
        cout << LamborghiniCar::output();
    } else if (magicNumber == 2) {
        cout << PorscheCar::output();
    } else {
        cout << "Please input a number between 1 and 2!";
    }

    cout << endl;

    return EXIT_SUCCESS;
}