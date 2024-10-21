/* c++11 introduced parameter pack, a way to receive 0 or more
template arguments works with both function and class templates
A template that has a parameter pack is called a variadic template,
since it is a template that accepts a varying number of parameters */
#include <string>
#include <vector>

template<typename... Types>
void do_action();

template<typename... Types>
struct MyStruct { };

// expand the parameter pack
template<typename... Types>
void do_action_expand(Types... types);
/* note:
a parameter pack in the list of template parameters can only be
followed by template parameters that have a default value,
or those that are deduced by the compiler. Most commonly,
the parameter pack is the last in the list of template parameters. */

// taking this variadic struct...
template<typename... Ts>
struct Variadic
{
    Variadic(Ts... arguments);
};

// writing a function that creates it
template<typename... Ts>
Variadic<Ts...> instantiate_variadic(Ts... args) {
    return Variadic<Ts...>(args...);
}

/* we can access type aliases declared in the type
or we can call a function on the parameter */
template<typename... Containers>
std::tuple<typename Containers::value_type...> get_front(Containers... containers) {
    return std::tuple<typename Containers::value_type...>(containers.front()...);
}

int main()
{
    do_action<int, std::string, float>();
    do_action<>();
    MyStruct<> myStruct1;
    MyStruct<float, int> myStruct2;

    do_action_expand();
    do_action_expand(1, 2, 4.5, 3.5f);

    std::vector<int> int_vector = { 1 };
    std::vector<double> double_vector = { 2.0 };
    std::vector<float> float_vector = { 3.0f };

    get_front(int_vector, double_vector, float_vector);
    // returns a tuple<int, double, float> containing { 1, 2.0, 3.0 }

    return 0;
}