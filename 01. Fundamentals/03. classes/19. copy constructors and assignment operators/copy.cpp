#include <iostream>

// copy constructor
class class_name
{
    public:
        class_name(const class_name& other) : member(other.member) { }

    private:
        int member;
};

// copy constructor example
struct A
{
    A() { }
    A(const A& a) {
        std::cout << "Copy construct A" << std::endl;
    }
};

struct B
{
    B() { }
    B(const B& a) {
        std::cout << "Copy construct B" << std::endl;
    }
};

class C
{
    A a;
    B b;
    // the copy constructor is implicitly generated
};

// copy assignment operator
class class_name2
{
    public:
        class_name2& operator = (const class_name2& other) {
            member = other.member;
            return *this;
        }

        private:
            float member;
};

// copy constructor and assignment example
class class_name3
{
    public:
        class_name3() { }

        class_name3(const class_name3& other) : member(other.member) {
            std::cout << "Copy constructor called!" << std::endl;
        }

        class_name3& operator = (const class_name3& other) {
            member = other.member;
            std::cout << "Copy assignment operator called!" << std::endl;
            return *this;
        }

    private:
        double member;
};

int main()
{
    C first;
    C second(first);

    class_name3 obj;
    class_name3 other_obj1(obj);
    class_name3 other_obj2;
    other_obj2 = obj;

    // class_name3 other_obj2 = obj;
    /* this line doesn't call the assignment operator
    because the assignment operator is called when
    modifying an already existing object,
    while the constructor is used when creating a new object */ 

    return 0;
}