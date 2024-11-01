/* In addition to capturing variables one by one, all variables in the scope can be
captured by simply writing [=] or [&]

Using [=] means that every variable will be captured by value, whereas [&] captures
all variables by reference

If inside a class, it is also possible to capture the class member variables by
reference using [this] and by copy by writing [*this] */

#include <iostream>

class Foo
{
    public:
        auto member_function() {
            auto a = 0;

            auto b = 1.0f;

            // Capture all variables by copy
            auto lambda_0 = [=]() { std::cout << a << b << _m; };

            // Capture all variables by reference
            auto lambda_1 = [&]() { std::cout << a << b << _m; };
            
            // Capture member variables by reference
            auto lambda_2 = [this]() { std::cout << _m; };
            
            // Capture member variables by copy
            auto lambda_3 = [*this]() { std::cout << _m; };
        }

    private:
        int _m { };
};

/* Note that using [=] does not mean that all variables in the scope are copied
into the lambda, only the variables actually utilized are copied

Although it is convenient to capture all variables with [&] or [=], we recommend
capturing variables one by one, as it improves the readability of the code by
clarifying exactly which variables are used inside the lambda scope

When capturing all variables by value, you can specify variables to be captured by
reference (and vice versa). The following table shows the result of different
combination in the capture block */


/* Capture block -> Resulting capture types */
int a, b, c;
auto func = [=](){}; /* -> Capture a, b, c by value */

int a, b, c;
auto func = [&](){}; /* -> Capture a, b, c by reference */

int a, b, c;
auto func = [=, &c](){}; /* -> Capture a, b by value; capture c by reference. */

int a, b, c;
auto func = [&, c](){}; /* -> Capture a, b by reference; capture c by value */