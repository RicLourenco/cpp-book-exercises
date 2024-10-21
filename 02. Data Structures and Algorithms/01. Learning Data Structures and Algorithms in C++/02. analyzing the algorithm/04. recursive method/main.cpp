/* n the previous code sample, we calculated the complexity of the iterative
method. Now, let's do this with the recursive method. Suppose we need to calculate
the factorial of a certain number, for instance 6, which will produce
6 * 5 * 4 * 3 * 2 * 1 = 720. For this purpose, we can use the recursive method,
which is shown in the following code snippet */

int Factorial(int n)
{
    if(n == 1) {
        return 1;
    }

    return n * Factorial(n - 1);
}

/* For the preceding function, we can calculate the complexity similarly to how we
did for the iterative method, which is f(n) = n since it depends on how much data
is being processed (which is n). We can use a constant, for instance c, to
calculate the lower bound and the upper bound */