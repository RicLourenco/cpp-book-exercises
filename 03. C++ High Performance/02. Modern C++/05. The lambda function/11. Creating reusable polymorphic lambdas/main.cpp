/* Here are two vectors, one resembling a farm with the number of animals, and the
other one mapping countries to their corresponding continent */

#include <vector>
#include <utility>
#include <string>
#include <algorithm>

auto farm = std::vector<std::pair<std::string, int>>
{
    { "Bear", 5 },
    { "Deer", 0 },
    { "Pig", 4 }
};

enum class Continent
{
    Europe,
    Asia,
    America
};

auto countries = std::vector<std::pair<std::string, Continent>>
{
    { "Sweden", Continent::Europe },
    { "India", Continent::Asia },
    { "Belarus", Continent::Europe },
    { "Mexico", Continent::America }
};

/* Let's say we want to sort the animals in order of how many the farm contains,
and the countries in order of the continent they belong to. Speaking in code, we
want to sort the vectors according to the std::pair::second member. As the vectors
contain different value types, we use a polymorphic lambda. In order to avoid code
duplication, we tie the lambda to a variable, and the lambda can be used for
sorting both vectors */

auto lambda_sort()
{
    auto less_by_second = [](const auto &a, const auto &b) {
    return a.second < b.second;
    };

    /* Both vectors can be sorted with the same lambda */
    std::sort(farm.begin(), farm.end(), less_by_second);
    std::sort(countries.begin(), countries.end(), less_by_second);
}

/* Creating a reusable lambda for sorting like this is straightforward as we don't
require any captures. However, what do we do if we want to make a reusable lambda
which requires a capture?

For example, let's say we want to count the number of animals we have five of, or
the number of countries in Europe. What we have to do is to wrap the capture into a
function like this */

template<typename T>
auto is_second_equal(const T &x)
{
    /* A lambda capturing x is returned */
    return [&x](const auto &p) {
        return p.second == x;
    };
}

auto missing_animals = std::count_if(farm.begin(), farm.end(), is_second_equal(0));
/* missing_animals equals 1 as there are no deers in the farm */

auto num_european_countries = std::count_if(
    countries.begin(),
    countries.end(),
    is_second_equal(Continent::Europe)
);
/* num_european_countries is two as Sweden and Belarus are in Europe */

/* As you see, the template function is_second_equal is utilized as a proxy to make
the capture type a template. Then, the returned polymorphic lambda does not need to
know about the full type of the pair. The actual lambda function isn't generated
until the std::count_if is invoked

So, the compiler stumbles upon the following line */

auto lambda = is_second_equal(5);

/* It then starts by generating a function which returns a polymorphic lambda where
x is an int like this */

auto is_second_equal_int(const int &x) {
    return [&x](const auto &p) {
        return p.second == x;
    };
}

/* When that function is generated, the compiler goes on and generates a class
similar to this */

class Lambda
{
    public:
        Lambda(const int &x) : _x{x} {}

        template <typename T>

        auto operator()(const T &p) const { return p.second == _x; }

        int _x{ };
};

/* Then, an object of this Lambda class is constructed and passed to the algorithm
like this */

auto missing_animals = std::count_if(farm.begin(), farm.end(), Lambda { 0 });

/* The template operator() member function of the Lambda class is further converted
to the following function */

auto operator()(const std::pair<std::string, int> &p) const {
    return p.second == _x;
};