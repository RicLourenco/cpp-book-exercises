#include "animal.h"

int main()
{
    Dog dog = Dog("Bulldog");
    AnimalTemplate<Dog> dogTemplate(dog);
    dogTemplate.GetNameAndMakeSound();

    Cat cat = Cat("Persian Cat");
    AnimalTemplate<Cat> catTemplate(cat);
    catTemplate.GetNameAndMakeSound();

    return 0;
}