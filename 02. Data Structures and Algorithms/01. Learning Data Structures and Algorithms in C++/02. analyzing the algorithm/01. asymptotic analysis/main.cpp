/* start with asymptotic analysis to find out the time complexity of the
algorithms. This analysis omits the constants and the least significant parts.
Suppose we have a function that will print a number from 0 to n */

#include <iostream>

void Looping(int n)
{
    int i = 0;

    while (i < n) {
        std::cout << i << std::endl;
        i = i + 1;
    }
}

/* Now, let's calculate the time complexity of the preceding algorithm by counting
each instruction of the function. We start with the first statement

int i = 0;

The preceding statement is only executed once in the function, so its value is 1.
The following is the code snippet of the rest statements in the Looping() function:

while (i < n) {
    cout << i << endl;
    i = i + 1;
}

The comparison in the while loop is valued at 1. For simplicity, we can say that
the value of the two statements inside the while loop scope is 3 since it needs 1
to print the i variable, and 2 for assignment (=) and addition (+). However, how
much of the preceding code snippet is executed depends on the value of n, so it
will be (1 + 3) * n or 4n. The total instruction that has to be executed for the
preceding Looping() function is 1 + 4n. Therefore, the complexity of the preceding
Looping() function is:

Time Complexity(n) = 4n + 1

the curve is linear. However, since the time complexity also depends on the other
parameters, such as hardware specification, we may have another complexity for the
preceding Looping() function if we run the function on faster hardware. Let's say
the time complexity becomes 2n + 0.5

we can omit a constant and the least significant parts in asymptotic analysis, so
we can say that the preceding complexity is n, as found in the following notation:

Time Complexity(n) = n


Let's move on to another function. If we have the nested while loop, we will have
another complexity, as we can see in the following code */

void Pairing(int n)
{
    int i = 0;

    while (i < n) {
        int j = 0;

        while (j < n) {
            std::cout << i << ", " << j << std::endl;
            j = j + 1;
        }

        i = i + 1;
    }
}

/* Based on the preceding Looping() function, we can say that the complexity of the
inner while loop of the preceding Pairing() function is 4n + 1. We then calculate
the outer while loop so it becomes 1 + (n * (1 + (4n + 1) + 2), which equals
1 + 3n + 4n2. Therefore, the complexity of the preceding code is:

Time Complexity(n) = 4n2 + 3n + 1

And if we run the preceding code in the slower hardware, the complexity might
become twice as slow. The notation should be as follows:

Time Complexity(n) = 8n2 + 6n + 2

since the asymptotic analysis omits the constants and the least significant parts,
the complexity notation will be as follows:

Time Complexity(n) = n2 */