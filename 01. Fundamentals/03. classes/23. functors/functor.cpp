#include <iostream>
#include <string>

class class_name
{
    public:
        int operator()(int arg) { }
};

/* the following is a simple example of a functor that prints a string
before appending a new line at the end of it */
class logger
{
    public:
        void operator()(const std::string &s) {
            std::cout << s << std::endl;
        }
};

int main()
{
    class_name obj;
    int t;
    /* obj is an instance of a class with the call operator:
    it can be used as if it was a function */
    obj(t);

    logger log;
    log("hello world!");
    log("keep learning c++");

    return 0;
}