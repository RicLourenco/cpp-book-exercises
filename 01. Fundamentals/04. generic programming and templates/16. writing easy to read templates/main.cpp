#include <string>

// type alias
class UserAccount
{
    std::string Id;
    double balance;
    std::string email;
};

/* We want to organize the user accounts into a high scoreboard based on their
account balances to visualize which users are most actively using our service.
To do so. we can use a data structure that requires a few parameters:
the type to store, a way for ordering the types, a way to compare the types,
and possibly others */

// could be as follows
template<typename T, typename Comparison = Less<T>, typename Equality = Equal<T>>
class SortedContainer { };

/* hypothetically we implemented two structures to compare user account since
UserAccount doesn't implement the < operator and == doesn't do what we want */
SortedContainer<UserAccount, UserAccountBalanceCompare, UserAccountBalanceEqual> highScoreBoard;

// but using a type alias we could instead write the following
using HighScoreBoard = SortedContainer<UserAccount, UserAccountBalanceCompare, UserAccountBalanceEqual>;

HighScoreBoard highScoreBoardAliased;

/* The second case is extremely useful for allowing code to introspect the class,
that is, looking into some of the details of the class */
template<typename T>
class sortedContainer
{
    public:
        T& front() const;
        // a common pattern is to use a type alias
        using value_type = T;
};

template<typename T>
class ReversedContainer
{
    public:
        T& front() const;
        using value_type = T;
};

/* with the above type alias the function can access the type of the
element and return it */
template<typename Container>
typename Container::value_type& get_front(const Container& container);
/* note
Remember that value_type depends on the Container type, so it is a dependent type
When we use dependent types, we must use the typename keyword in front */

// avoiding using the typename keyword repeatedly
template<typename Container>
class ContainerWrapper
{
    public:
        using value_type = typename Container::value_type;
        /* in the rest of the class we can use the value_type without having to
        type typename anymore */
};

// the three techniques can also be combined
template<typename T>
class MyObjectWrapper
{
    using special_type = MyObject<typename T::value_type>;
};


int main()
{
    return 0;
}