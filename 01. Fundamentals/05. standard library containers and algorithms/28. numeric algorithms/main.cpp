/* accumulate: takes the beginning and end of a range, an initial value and an optional
binary predicate. combines all elements in the range with the initial value using the
binary predicate. if the binary predicate isn't provided, the + operator is used */

#include <iostream>
#include <vector>
#include <algorithm>
// the book forgot to tell, but it's included in the <numeric> header
#include <numeric>

int main()
{
    std::vector<int> costs = { 1, 2, 3 };

    int budget = 10;
    int margin = std::accumulate(
        costs.begin(),
        costs.end(),
        budget,
        [ ] (int a, int b) {
            return a - b;
        }
    );
    std::cout << "Margin: " << margin << std::endl;

    return 0;
}