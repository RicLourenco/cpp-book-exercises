/* most of the algorithms accept a unary of binary predicate: a functor
(function object) which accepts either one or two parameters. these
predicates allow the user to specify some of the actions that the
algorithm requires
a lambda expression creates a special function object, with a type known
only by the compiler, which behaves lika a function but can access the
variables inside the scope in which it was created.
it's defined with the syntax: [captured variables] (arguments) { body }
this creates an object that when called with the args specified in the
lambda expression, executes the body of the function */

#include <iostream>

int main()
{
    // lambda that takes two integers and returns their sum
    auto sum_numbers = [ ] (int a, int b) { return a + b; };
    std::cout << sum_numbers(10, 20) << std::endl;

    /* By default, the body of the lambda can only reference the variables
    that are defined in the argument list and inside the body, like for
    functions. additionally, lambdas can capture a variable in the local
    scope and use it in their body. captured variables entail a list of
    variable names that can be referenced in the body of the lambda. When
    a variable is captured, it is stored inside the created function object,
    and it can be referenced in the body. by default, the variables are
    captured by value, so they are copied inside the function object */
    int addend = 1;
    auto sum_numbers_addend = [addend] (int b) { return addend + b; };
    addend = 2;
    std::cout << sum_numbers_addend(3) << std::endl;

    /* when we created the lambda, we captured the addend by value: it
    was copied into the sum_numbers object. even if we modified the value
    of addend, we did not change the copy stored inside sum_numbers, so
    when sum_numbers is executed, it sums 1 to b. in some situations we
    want to be able to modify the value of a variable in the scope in which
    the lambda was created, or we want to be able to access the actual
    value, not the value the variable had when the lambda was created, in
    that case we can capture by reference by prepending & to the variable
    name.
    note : When we capture by reference, we need to make sure that the
    variable that's been captured by reference is still valid when the lambda
    is invoked, otherwise the body of the function accesses an invalid object,
    resulting in bugs. Prefer to capture by value when it is possible */
    int multiplier = 1;
    auto multiply_numbers = [&multiplier] (int b) { return multiplier * b; };
    multiplier = 2;
    std::cout << multiply_numbers(3) << std::endl;
    
    /* A lambda can capture multiple variables, and each one can be either
    captured by value or by reference, independently one from the other */

    return 0;
}