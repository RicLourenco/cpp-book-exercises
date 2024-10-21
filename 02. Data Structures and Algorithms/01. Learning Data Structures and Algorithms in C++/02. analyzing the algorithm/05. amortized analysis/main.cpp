/* In the previous section, we just discussed the single input, n, for calculating
the complexity. However, sometimes we will deal with more than just one input.
Please look at the following SumOfDivision() function implementation */

int SumOfDivision(int nArr[], int n, int mArr[], int m)
{
    int total = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            total += (nArr[i] * mArr[j]);
        }
    }

    return total;
}

/* And that's where amortized analysis comes in. Amortized analysis calculates the
complexity of performing the operation for varying inputs, for instance, when we
insert some elements into several arrays. Now, the complexity doesn't only depend
on the n input only, but also the m input. The complexity can be as follows:

Time Complexity(n, m) = n · m */