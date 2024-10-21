#include <string>
#include <vector>

template<typename T>
T createFrom(const T& other) {
    return T(other);
}

template<typename A, typename B>
A transform(const B& b) {
    return A(b);
}

template<typename A, typename B>
A createFrom() {
    B factory;
    return factory.GetA();
}

struct Account
{
    // some fields
};

class user
{
    public:
        Account getAccount() const {
            return Account();
        }
};

// requirements for template parameter types
template <typename Container, typename user>
void populateAccountCollection(Container& container, const user& user) {
    container.push_back(user.getAccount());
}

// trailing return types
auto max(int a, int b) -> int {
    if(a < b) {
        return b;
    }
    return a;
}

/* in c++14 a function can return auto without needing trailing return type
also an auto returning function always returns a value, never a reference
also can't be forward declared */
auto max(float a, float b) {
    if(a < b) {
        return b;
    }
    return a;
}

/* This is not beneficial when writing regular functions,
but it becomes useful when writing templates and when combined with decltype
The reason for this is that decltype has access to the variables defined in the
parameters of the function, and the return type can be computed from them */
template<typename user>
auto getAccount(user user) -> decltype(user.getAccount()) {
    return user.getAccount();
}

/* We know that a template is just a blueprint for a function,
and the real function is going to be created only when the template is instantiated.
C++ allows us to instantiate the template function even without calling it.
We can do this by specifying the name of the template function,
followed by the template parameters, without adding the parameters for the call. */
template<typename T>
void sort(std::array<T, 5> array, bool (*function)(const T&, const T&));

/* the above sort function takes an array of 5 elements and a pointer to
the function below that compares two elements*/
template<typename T>
bool less(const T& a, const T& b) {
    return a < b;
}


int main()
{
    std::vector<Account> accounts;
    user user;
    populateAccountCollection(accounts, user);

    // decltype
    int x;
    decltype(x) y;
    decltype(user.getAccount()) account;

    // this calls sort with an instance of the less template for int
    std::array<int, 5> array = { 4, 3, 5, 1, 2 };
    sort(array, &less<int>);

    return 0;
}