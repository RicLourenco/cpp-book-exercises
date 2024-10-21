#include <vector>

// public aliases
template<typename T>
class MyArray
{
    /* typical example would be the value_type type alias for containers,
    which specifies the type contained */
    using value_type = T;

    /* The reason for this is that if we are accepting a generic array
    as a template parameter, we might want to find out the contained type */
    
    /* If we were accepting a specific type, this problem would not arise.
    Since we know the type of vector, we could write the following code */
    void createOneAndAppend(std::vector<int>& container) {
        int new_element { };
        container.push_back(new_element);
    }

    /* but if we want to accept any type that provides the push_back method,
    we can access the type alias, which specifies which kind of value it contains */
    template<typename Container>
    void createOneAndAppend(Container& container) {
        typename Container::value_type new_element;
        container.push_back(new_element);
    }

    /* but this does not compile
    value_type is a dependent type, as such it's derived from one of the
    template parameters
    when the compiler compiles this code, it notices we are accessing the
    value_type identifier in the Container class, which could either be
    static field or a type alias */
};