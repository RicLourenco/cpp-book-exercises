#include <iostream>

using namespace std;

bool isSafeHeightForRollercoaster(int heightInCm)
{
    bool isSafe = heightInCm > 100 && heightInCm < 210;
    return isSafe;
}

bool isSafeHeightForRollercoaster(float heightInM)
{
    bool isSafe = heightInM > 1.0f && heightInM < 2.1f;
    return isSafe;
}

int main()
{
    // Calls the int overload
  isSafeHeightForRollercoaster(187);

  // Class the float overload
  isSafeHeightForRollercoaster(1.67f);

    return EXIT_SUCCESS;
}