/* Although having a complex-sounding name, a polymorphic lambda is simply a lambda
accepting auto as a parameter, making it possible to invoke it with any type. It
works just like a regular lambda, but the operator() has been defined as a member
function template

Only the parameters are template variables, not the captured values. In other
words, the captured value v in the following example will stay as an integer

So, if you define a polymorphic lambda like this */

#include <iostream>

auto poly_lambda()
{
    auto v = 3;
    auto lambda = [v](auto v0, auto v1) {
        return v + v0 * v1;
    };

    return lambda;
}

/* If we translate the above lambda to a class, it would correspond to something
like this */

class Lambda
{
    public:
        Lambda(int v) : _v{ v } { }
        template<typename T0, typename T1>
        auto operator() (T0 v0, T1 v1) const
        {
            return _v + v0 * v1;
        }

    private:
        int _v { };
};

auto equivalent_class()
{
    auto v = 3;
    auto lambda = Lambda { v };
}

/* This means that, just like the templated version, the compiler won't generate
the actual function until the lambda is invoked

So, we can invoke the previous lambda like this */

int main()
{
    auto lambda = poly_lambda();

    auto res_int = lambda(1, 2);
    auto res_float = lambda(1.0f, 2.0f);

    std::cout << "res_int: " << res_int << "\n";
    std::cout << "res_float: " << res_float << std::endl;
}

/* The compiler will generate something similar to the following lambdas */

// auto lambda_int = [v](int v0, const int v1) { return v + v0*v1; };
// auto lambda_float = [v](float v0, float v1) { return v + v0*v1; };
// auto res_int = lambda_int(1, 2);
// auto res_float = lambda_float(1.0f, 2.0f);