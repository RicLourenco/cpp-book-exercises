template<typename T>
void foo(T parameter) {
    // something
}

template<typename A, typename B, typename C>
C foo(A, B) {
    // something
}

template<typename C, typename A, typename B>
C bar(A, B) {
    // something
}

int main()
{
    // call
    int argument;
    foo(argument);

    /* the compiler can't deduce a type if it's only used
    in the return type or inside the function body,
    in this case for example the compiler can deduce A and B but not C */
    foo(1, 2.23);

    // so we need to provide all the types in order
    foo<int, double, float>(1, 2.23);

    /* now in this case we put the type that cannot be deduce before the
    types that can be deduced, now we can specify only that type
    and the compiler will deduce the other two types */
    bar<float>(1, 2.23);

    return 0;
}