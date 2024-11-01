/* Mutating lambda member variables

As the lambda function works just like a class with member variables, it can also
mutate them. In the following example, the lambda mutates the threshold variable
every time it is invoked. In order to allow the lambda to mutate its members, we
need to specify mutable when declaring the lambda. The mutable modifier on a lambda
function works like the inverse for a const modifier for a regular class member
function; in contrast to a class member function, a lambda function is const by
default, and therefore a mutating lambda must be explicitly specified */

#include <cassert>
#include <iostream>

/* Capture by value */

auto func()
{
    auto v = 7;
    auto lambda = [v]() mutable
    {
        std::cout << v << " ";
        ++v;
    };
    
    assert(v == 7);
    lambda();
    lambda();
    assert(v == 7);
    std::cout << v;
}
/* Output: 7 8 7 */

/* Capture by reference */

auto func()
{
    auto v = 7;
    auto lambda = [&v]()
    {
        std::cout << v << " ";
        ++v;
    };
    assert(v == 7);
    lambda();
    lambda();
    assert(v == 9);
    std::cout << v;
}
/* Output: 7 8 9 */

/* If we want to capture the v by reference instead, we do not have to specify the
mutable keyword as the lambda itself doesn't mutate. Instead, the original v in
func will mutate, meaning that we have a different output


Mutating member variables from the compiler's perspective

To understand what's going in the above example, take a look at how the compiler sees the
previous lambda objects */

/* Capture by value case  */
class MutatingLambda
{
    public:
        MutatingLambda(int m) : v(m) { }

        auto operator()() {
            std::cout << v << " ";
            ++v;
        }

    private:
        int v { };
};

/* Capture by reference case */
class MutatingLambda
{
    public:
        MutatingLambda(int &m) : v(m) { }

        auto operator()() const {
            std::cout << v << " ";
            ++v;
        }

    private:
        int &v;
};

/* You might have noticed that we add the modifier const on the operator() member
function of the capture by reference class, and we also do not specify mutable on
the corresponding lambda. The reason this class is still considered const is that
we do not mutate anything inside the actual class/lambda; the actual mutation
applies to the referenced value, and therefore the function is still considered
const */