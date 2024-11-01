/* As mentioned before, every lambda function has its own type, even if they have
the same signature (and even if they are identical)

The signature of a std::function is defined as follows:
std::function<return_type(parameter 0, parameter 1, ...)> */

/* So, a std::function returning nothing and having no parameters is defined like
this */
#include <iostream>
#include <functional>
#include <string>

auto func = std::function<void(void)> { };

/* A std::function returning a bool and having an int and a std::string as
parameters is defined like this */
auto func = std::function<bool(int, std::string)> { };


/* Assigning lambdas to std::functions

As mentioned earlier, every lambda function has its own type, and therefore cannot
be assigned to other lambda functions, even if they look exactly the same. However,
a std::function can hold any lambda function which has the same signature, that is,
it has the same parameters and the same return value. A std::function can also be
reassigned at run time. This makes std::function the type to use if you want a
variable to hold a lambda function

What is important here is that what is captured by the lambda does not affect its
signature, and therefore both lambdas with and without captures can be assigned to
the same std::function

The following code block shows how different lambdas are assigned the same
std::function object */

/* Create an unassigned std::function object */
auto func = std::function<void(int)> { };

/* Assign a lambda without capture to the std::function object */
func = [](int v)
{
    std::cout << v;
};

func(12); /* Prints 12 */

/* Assign a lambda with capture to the same std::function object */
auto forty_two = 42;
func = [forty_two](int v)
{
    std::cout << (v + forty_two);
};

func(12); /* Prints 54 */