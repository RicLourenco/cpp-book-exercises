#include <iostream>

class Apple
{
    private:
        Apple() {
            
        };

    public:
        friend class AppleTree;
};

class AppleTree
{
    public:
        Apple createApple() {
            Apple apple;
            std::cout << "apple created!";
            return apple;
        }
};

int main()
{
    AppleTree tree;
    Apple apple = tree.createApple();
}