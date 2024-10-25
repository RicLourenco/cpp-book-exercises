/* Take a look at the following C/C++ code snippets, which correspond to the
question: "How many copies of Hamlet is in the list of books?" */

#include <list>

// C version
struct string_elem_t
{
    const char *str_;
    string_elem_t *next_;
};

int num_hamlet(string_elem_t *books)
{
    const char *hamlet = "Hamlet";
    int n = 0;
    string_elem_t *b;

    for (b = books; b != 0; b = b->next_) {
        if (strcmp(b->str_, hamlet) == 0) {
            ++n;
        }
    }
    return n;
}

// C++ version
int num_hamlet(const std::list<std::string>& books)
{
    return std::count(books.begin(), books.end(), "Hamlet");
}