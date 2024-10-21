/* variant is a vlaue type that's used to represent a choice of types,
the class takes a list of types and will be able to contain one value
of any of those types. it's often refered to as tagged union, it can
store multiple types with only one present at a time, also keeps track
of which type is currently stored. like optional, it's a value type,
so when we create a copy of variant, the element that is currently
stored is copied into the new variable */

#include <variant>
#include <string>

int main()
{
    // there are two main function to let us interact with a variant

    std::variant<std::string, int> variant = 42;

    // holds_aternative()
    std::holds_alternative<std::string>(variant);
    /* returns true if the variant is holding the specified type,
    otherwise false */

    // and get()
    std::get<std::string>(variant); // or...
    std::get<0>(variant);
    /* get<type> returns the value of the type that's currently stored
    inside the variant, also before doing this, make sure
    holds_alternative<type> returns true. get<index> gets the value of
    the index type, also again make sure variant holds the correct type */

    return 0;
}