#include <variant>
#include "visitor.h"

int main()
{
    std::variant<std::string, int> variant = 42;
    visitor::Visitor visitor;
    std::cout << "The variant contains ";
    std::visit(visitor, variant);
    variant = std::string("Hello World!");
    std::cout << "Now the variant contains ";
    std::visit(visitor, variant);

    return 0;
}

/* extra example: variant is very valuable when we want to represent a set of values of
different types for example: a function returning different types depending on the
current state of the program; a class that represents several states. let's say the
following */
class User { };
struct UserRegistrationForm { };

/* thanks to variant, the following function can return either a User or a
UserRegistrationForm depending on if the user is registered or not */
std::variant<User, UserRegistrationForm> getUserByEmail() { }

/* also what to do when there is an error? with variant there could be a struct
GetUserError storing all the information we have so that our application can
recover from the error and add it to the return type */
struct GetUserError { };
std::variant<User, UserRegistrationForm, GetUserError> tryGetUserByEmail() { }