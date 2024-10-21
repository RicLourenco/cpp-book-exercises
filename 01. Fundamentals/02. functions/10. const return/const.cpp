#include <array>

// This should clearly take a reference to the array since its purpose is to modify the array
void setTheThirdItem(std::array<int, 10>& array, int item);

// This tells us that we are only looking into the array – we are not changing it, so we should use const
int findFirstGreaterThan(const std::array<int, 10>&  array, int threshold);

// default arguments
char const * firstWord(char const * string, char separator = ' ');