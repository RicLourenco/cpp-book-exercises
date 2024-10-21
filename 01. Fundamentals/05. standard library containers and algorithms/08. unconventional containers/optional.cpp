/* optional<T> is a container that's used to contain a value that might
be present or not. the class takes a template parameter T representing
the type it might contain. value type means that the instance of the
class contains the value, and copying optional will create a new copy
of the contained data
contained the <optional> header */
#include <iostream>
#include <optional>
#include <string>

int main()
{
    // we might not know the hour, but if we know it, it's an integer
    std::optional<int> currentHour;

    if(not currentHour.has_value()) {
        std::cout << "we don't know the time" << std::endl;
    }

    currentHour = 18;

    if(currentHour) {
        std::cout << "current hour is: " << currentHour.value() << std::endl;
    }

    /* we can assign the std::nullopt value to optional to make explicit
    we want it empty, and we can use make_optional value to create an
    optional out of an already existing value.
    additionally we can access the value of optional with a dereference
    operator: *, to access the value of optional without throwing an
    exception if the value isn't present, however this will access invalid
    memory, so it's important to make sure the optional contains a value */
    std::optional<std::string> mayberUser = std::nullopt;
    if(not mayberUser) {
        std::cout << "the user is not present" << std::endl;
    }

    mayberUser = std::make_optional<std::string>("email@example.com");
    if(mayberUser) {
        std::cout << "the user is: " << *mayberUser << std::endl;
    }

    /* another method is value_or(defaultValue) which takes a default value
    adn returns the value contained by optional if it does contain a value,
    otherwise it returns a default value */

    // this will return value of 10
    std::optional<int> x;
    std::cout << x.value_or(10) << std::endl;

    // this will return 15
    x = 15;
    std::cout << x.value_or(10) << std::endl;
}

/* sometimes optional is good for accepting arguments that may or not be
present, so for example we could make a constructor to take optional values
instead of making different constructors for every possible combination of
overloads */
class user
{
    std::string email;
    std::optional<std::string> address, phoneNumber;

    user(std::string email, std::optional<std::string> address = std::nullopt,
        std::optional<std::string> phoneNumber = std::nullopt)
        : email(email), address(address),
        phoneNumber(phoneNumber) { }
};