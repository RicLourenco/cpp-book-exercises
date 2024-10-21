#include <iostream>

using namespace std;

const int pos = 10;
const int computed = 3;

void print_tenth_fibonacci()
{
    int n_1 = 1;
    int n_2 = 0;
    int current = n_1 + n_2;

    for (int i = computed; i < pos; i++) {
        n_2 = n_1;
        n_1 = current;
        current = n_1 + n_2;
    }

    cout << current << endl;
}

int main()
{
    cout << "Computing the 10th Fibonacci number" << "\n";
    print_tenth_fibonacci();

    return 0;
}