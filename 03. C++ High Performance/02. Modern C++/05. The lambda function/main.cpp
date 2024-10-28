/* You can store a lambda function in std::function

Although the lambda function made these programming techniques vastly simpler to
work with, everything here is possible to perform without them by making classes
with operator() overloaded

We will explore the lambda function's similarities to these kind of classes later,
but first let's introduce the lambda function in a simple use case

In a nutshell, the lambda function capability enables programmers to pass functions
to regular functions, just as easily as a variable is passed */

#include <vector>

// Prerequisite
auto vals = std::vector<int> {
    1, 2, 3, 4, 5
};

// Look for number 3
auto three = 3;

auto num_threes = std::count(vals.begin(), vals.end(), three);
// num_threes is 1

// Look for a number which is larger than three
auto is_above_three = [](int v)
{
    return v > 3;
};

auto num_above_three = std::count(vals.begin(), vals.end(), is_above_three);
// num_above_three is 2

/* Notice how we pass a variable to search for with std::count() in the first case,
and a function to search for with std::count_if() in the latter case. This is a
typical use case for lambda functions: we pass a function to be evaluated many
times to another function (in this case, std::count_if)

Also, the lambda does not need to be tied to a variable; just as we can put a
variable right into an expression, we can do the same with a lambda function: */

auto num_three = std::count(vals.begin(), vals.end(), 3);

auto num_above_three = std::count(vals.begin(), vals.end(), [](int v) {
    return v > 3;
});