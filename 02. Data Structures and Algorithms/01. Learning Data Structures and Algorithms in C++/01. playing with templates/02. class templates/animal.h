#include <iostream>

class Animal
{
    protected:
        std::string m_name;

    public:
        Animal(std::string name) : m_name(name) { }

        // the interface that has to be implemented in derived class
        virtual std::string MakeSound() = 0;

        std::string GetName() {
            return m_name;
        }
};

class Dog : public Animal
{
    public:
        // forward the constructor arguments
        Dog(std::string name) : Animal(name) { }

        // copy assignment operator overloading
        void operator = (const Dog &D) {
            m_name = D.m_name;
        }

        // here we implement the interface
        std::string MakeSound() override {
            return "woof-woof!";
        }
};

class Cat : public Animal
{
    public:
        // forward the constructor arguments
        Cat(std::string name) : Animal(name) { }

        // copy assignment operator overloading
        void operator = (const Cat &C) {
            m_name = C.m_name;
        }

        // here we implement the interface
        std::string MakeSound() override {
            return "meow-meow!";
        }
};

template<typename T>
void GetNameAndMakeSound(T& animal) {
    std::cout << "The " << animal.GetName() << " goes " << animal.MakeSound() << std::endl;
}

template<typename T>
class AnimalTemplate
{
    private:
        T m_animal;

    public:
        AnimalTemplate(T animal) : m_animal(animal) { }

        void GetNameAndMakeSound() {
            std::cout << "The " << m_animal.GetName() << " goes " << m_animal.MakeSound() << std::endl;
        }
};