/* The capture block

Let's make this a little more advanced. In the previous example, we hard coded the
value we wanted to count numbers above. What if we want to use an external variable
inside the lambda instead? What we do is capture the external variables by putting
them in the capture block, that is, the [] part of the lambda */

#include <vector>
#include <iostream>

auto count_value_above(const std::vector<int>& vals, int th) {
    auto is_above = [th] (int v) {
        return v > th;
    };

    return std::count_if(vals.begin(), vals.end(), is_above);
};

/* In this example, we captured the th variable by copying it into the lambda
function, if we want to declare the th as a reference, we put a & at the beginning
like this */

// auto is_above = [&th] (int v) {
//     return v > th;
// };

/* The variable is now merely a reference to the outer th variable, just like a
regular reference variable in C++ */


/* Capture by reference versus capture by value

Using the capture block for referencing and copying variables works just like
regular variables. Take a look at these two examples

Capture by value: */
auto func_val()
{
    auto vals = {
        1, 2, 3, 4, 5, 6
    };

    auto th = 3;

    auto is_above = [th] (int v) {
        return v > th;
    };

    th = 4;

    auto count_b = std::count_if(
        vals.begin(),
        vals.end(),
        is_above
    );

    /* count_b equals 3 */
    std::cout << count_b << std::boolalpha << std::endl;
}

/* Capture by reference: */
auto func_ref()
{
    auto vals = {
        1, 2, 3, 4, 5, 6
    };

    auto th = 3;

    auto is_above = [&th] (int v) {
        return v > th;
    };

    th = 4;

    auto count_b = std::count_if(
        vals.begin(),
        vals.end(),
        is_above
    );

    /* count_b equals 2 */
    std::cout << count_b << std::boolalpha << std::endl;
}

/* In the first example, the threshold was copied into the lambda functions and is
therefore not affected when th was mutated, therefore std::count_if() counts the
number of values above 3

In the second example, th is captured by reference, and therefore std::count_if()
counts the number of values above 4 instead */

int main()
{
    func_val();
    func_ref();

    return 0;
}