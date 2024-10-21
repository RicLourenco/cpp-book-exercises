#include "animal.h"

int main()
{
    Dog dog = Dog("Bulldog");
    GetNameAndMakeSound(dog);

    Cat cat = Cat("Persian Cat");
    GetNameAndMakeSound(cat);

    return 0;
}