/* A std::function has a few performance losses compared to a lambda function */


/* An std::function cannot be inlined

When it comes to lambda functions, the compiler has the ability to inline the
function call, that is, the overhead of the function call is eliminated. The
flexible design of std::function make it nearly impossible for the compiler to
inline a function wrapped in a std::function. This overhead can have an impact on
the performance if small functions wrapped in std::function are being called very
frequently */


/* An std::function heap allocates and captures variables

If a lambda function with captured variables/references is assigned to a
std::function, the std::function will, in most cases, allocate space on the heap to
store the captured variables (note that some implementations of std::function do
not heap-allocate if the size of the captured variable is less than a specific
threshold). This means that not only is there a slight performance penalty due to
heap allocation and the execution of std::function but also that it is slower, as
heap allocation implies cache misses (more about cache misses in Chapter 4, Data
Structures) */


/* Invoking an std::function requires a few more operations than a lambda

Calling a std::function is generally a bit slower than executing a lambda as a
little more code is involved, for example, executing 1 million function calls for a
std::vector of the explicit lambda type versus a std::vector of a corresponding
std::function as follows

Benchmark invocation without capture of lambda vs std::function */

#include <vector>
#include <functional>
#include <iostream>

auto test_direct_lambda()
{
    auto lbd = [](int v) {
        return v * 3;
    };

    using L = decltype(lbd);
    auto fs = std::vector<L> { };
    fs.resize(1000000, lbd);
    auto res = int { 0 };

    for (const auto &f : fs) {
        res = f(res);
    }

    return res;
}

auto test_std_function()
{
    auto lbd = [](int v) {
        return v * 3;
    };

    using F = std::function<int(int)>;
    auto fs = std::vector<F> { };
    fs.resize(1000000, lbd);
    auto res = int { 0 };

    for (const auto &f : fs) {
        res = f(res);
    }

    return res;
}


/* The first version, using the lambda directly, executes at roughly one-fourth of
the time compared to the second version, where we instead use a vector of
std::function */

int main()
{
    std::cout << "Direct lambda: " << test_direct_lambda() << std::endl;
    std::cout << "std::function: " << test_std_function() << std::endl;

    return 0;
}