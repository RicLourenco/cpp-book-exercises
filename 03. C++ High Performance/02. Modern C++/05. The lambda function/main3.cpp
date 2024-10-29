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