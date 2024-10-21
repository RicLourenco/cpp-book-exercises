#include <iostream>
// you fkin need to incluide <array> but the textbook didn't reference this
#include <array>

using namespace std;

const int& max(const int& a, const int& b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int& sum(int a, int b)
{
    int c = a + b;
    return c;
}

int& get_max_index(array<int, 3>& arr, int index1, int index2)
{
    // This function requires that index1 and index2 must be smaller than 3
    int max_index = max(index1, index2);
    return arr[max_index];
}

int main()
{
    //const int& a = max(1, 2);
    const int& a = max(1, 2) + max(3, 4);
    cout << a << "\n";
    cout << sum(1, 2) << "\n";

    array<int, 3> arr = {1, 2, 3};
    int& elem = get_max_index(arr, 0, 2);
    elem = 0;
    cout << arr[2];
    // Prints 0
}