#include <iostream>

/* The previous problem can be fixed by using an idiom called copy-and-swap, which
means that we perform the operations that might throw exceptions before we let the
application's state be modified by non-throwing swap functions */

struct Leaf { /* ... */ };
struct Branch { /* ... */ };

class OakTree
{
    public:
        auto& operator=(const OakTree& other)
        {
            /* First create local copies without modifying the OakTree objects.
            Copying may throw, but this operation will still be in a valid state */
            auto leafs = other._leafs;
            auto branches = other._branches;

            /* No exceptions thrown, we can now safely modify the state of this
            object by non-throwing swap */
            std::swap(_leafs, leafs);
            std::swap(_branches, branches);
            return *this;
        }
        std::vector<Leaf> _leafs;
        std::vector<Branch> _branches;
};