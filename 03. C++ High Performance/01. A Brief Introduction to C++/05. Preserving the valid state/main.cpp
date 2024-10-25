#include <vector>

/* Take a look at the following example. If the _branches = ot._branches operation
throws an exception due to being out of memory (_branches might be a very big
member variable), the tree0 method will be left in an invalid state containing a
copy of _leafs from tree1 and _branches that it had before */

struct Leaf { /* ... */ };
struct Branch { /* ... */ };

class OakTree
{
    public:
        auto& operator=(const OakTree& other)
        {
            _leafs = other._leafs;
            /* If copying the branches throws, only the leafs has been copied and
            the OakTree is left in an invalid state */
            _branches = other._branches;
            return *this;
        }
        std::vector<Leaf> _leafs;
        std::vector<Branch> _branches;
};

auto save_to_disk(const std::vector<OakTree>& trees)
{
    // Persist all trees...
}

auto oaktree_func()
{
    auto tree0 = OakTree {
        std::vector<Leaf> {
            1000
        },
        std::vector<Branch> {
            100
        }
    };

    auto tree1 = OakTree {
        std::vector<Leaf> {
            50
        },
        std::vector<Branch> {
            5
        }
    };

    try
    {
        tree0 = tree1;
    }
    catch(const std::exception& e)
    {
        // tree0 might be broken
        save_to_disk({
                tree0,
                tree1
            });
    }
}

/* We want the operation to preserve the valid state of tree0 that it had before
the assignment operation so that we can save all our oak trees (pretend we are
creating an oak tree generator application) and quit */