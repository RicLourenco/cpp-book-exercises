/* Similarities between a Lambda and a class

To understand what the lambda function consists of, one can view it as a regular class with
restrictions:
- The class only consists of one member function.
- The capture block is a combination of the class's member variables and its
constructor.
- Each lambda function has its own unique type. Even if two lambda functions are
plain clones of each other, they still have their own unique type

Lambda with capture by value... */
void lambda_value()
{
    auto th = 3;
    auto is_above = [th](int v)
    {
        return v > th;
    };
    auto test = is_above(5);
    /* test equals true */
}

/* ...corresponds to this class */
namespace
{
    auto th = 3;

    class IsAbove
    {
        public:
            IsAbove(int th) : th{th} {}
            /* The only member function */
            auto operator()(int v) const
            {
                return v > th;
            }

        private:
            int th{}; /* Members */
    };

    auto is_above = IsAbove{th};

    auto test = is_above(5);
}
/* test equals true


Lambda with capture by reference... */
void lambda_ref()
{
    auto th = 3;

    auto is_above = [&th] (int v)
    {
        return v > th;
    };
    
    auto test = is_above(5);
    /* test equals true */
}

/* ...corresponds to this class */
namespace
{
    auto th = 3;
    class IsAbove
    {
    public:
        IsAbove(int &th) : th{th} {}
        /* The only member function */
        auto operator()(int v) const
        {
            return v > th;
        }

    private:
        int &th; /* Members */
    };
    auto is_above = IsAbove{th};
    auto test = is_above(5);
    /* test equals true */
}


/* Initializing variables in capture

As seen in the previous example, the capture scope initializes member variables in
the corresponding class. This means that we can also initialize member variables
inside a lambda, which are only visible from inside the lambda */

#include <list>
#include <iostream>

/* Lambda function... */
auto func = [c = std::list<int>{4, 2}] ()
{
    for (auto v : c)
        std::cout << v;
};

func();
/* Output: 42

... corresponding class */
class Func
{
    public:
        Func() : c{ 4, 2 } { }
        auto operator()() const -> void
        {
            for (auto v : c)
                std::cout << v;
        }

    private:
        std::list<int> c;
};

auto func = Func { };

func();
/* Output: 42 */