/* A string can be converted into a null-terminating string, which
is an array of characters that terminate with the special null character
(represented with '\0') via the use of the data() or c_str() functions.
Null-terminating strings, also called C-strings, are the way to represent
sequences of character in the C language and they are often used when the
program needs to interoperate with a C library; they are represented with
the const char * type and are the type of the literal strings in our
programs */

#include <iostream>
#include <string>

int main()
{
    // construct a c-string being explicit about the null terminator
    const char charString[8] = { 'C', '+', '+', ' ', '1', '0', '1', '\0' };

    /* construct a c-string from a literal string, the compiler
    automatically adds the \0 at the end */
    const char * literalString = "C++ Fundamentals";

    // strings can be constructed from literal strings
    std::string strString = literalString;

    /* using the c_str() function and assign the value of strString
    to charString2 */
    const char *charString2 = strString.c_str();

    std::cout << charString << std::endl;
    std::cout << charString2 << std::endl;

    /* other functions:
        stoi(): string-to-int
        stod(): string-to-double
        to_string(): overloaded function to convert to string */
    std::string str = "55";
    int strInt = std::stoi(str);
    double strDouble = std::stod(str);
    std::string valToString = std::to_string(strInt);

    return 0;
}