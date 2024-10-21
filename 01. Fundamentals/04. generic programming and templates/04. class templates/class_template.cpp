#include <string>

template<typename T>
class MyArray
{
    /* there is no need to use MyArray<T> to refer to the class,
    MyArray automatically refers to the current template instantiation
    as seen below */
    
    public:
        // define the constructor for the current template T
        MyArray();

        // this is not a valid constructor
        // MyArray<T>();

        // methods can use the type parameter
        void push_back(const T& element);

        // can also have template methods, are similar to template functions
        template<typename Comparator>
        void sort(const Comparator& element);

        /* important to know how templated classes interact with static members
        when a templated class declares a static member, the member is shared only
        between the instantions of the template with the same template parameters */
        const static int element_size = sizeof(T);

    private:
        T[1] internal_array;
};

class MyComparator
{
    // something
};

/* if a templated method is only declared inside a class,
it can be later implemented by spedifying both the class
and the method's template types */
template<typename T> // template of the class
template<typename Comparator> // template of the method
void MyArray<T>::sort(const Comparator& element) {
    // implementation
}

int main()
{
    MyArray<int> myArray;
    // call sort templated method
    MyComparator comparator;
    myArray.sort<MyComparator>(comparator);

    /* both int_array will share the same static element_size variable
    while string_array will access a different variable because they have
    different type parameters even though they share the same class template */
    MyArray<int> int_array_1;
    MyArray<int> int_array_2;
    MyArray<std::string> string_array;

    return 0;
}