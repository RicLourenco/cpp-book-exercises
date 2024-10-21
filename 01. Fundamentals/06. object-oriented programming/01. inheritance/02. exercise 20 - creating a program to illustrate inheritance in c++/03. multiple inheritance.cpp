struct A { };

struct B { };

struct C : A, B { };

/* The rules on how inheritance works are the same for single and multiple
inheritance: the methods of all the derived classes are visible based on
the visibility access specified, and we need to make sure to call the
appropriate constructors and assign an operator for all of the base classes

note : It is usually best to have a shallow inheritance hierarchy: there
should not be many levels of derived classes

When using a multi-level inheritance hierarchy or multiple inheritance, it's
more likely that you'll encounter some problems, such as ambiguous calls. A
call is ambiguous when the compiler cannot clearly understand which method
to call. */

struct A
{
    void foo() { }
};

struct B
{
    void foo() { }
};

struct C: A, B
{
    void bar() {
        foo();
        /* In this example, it is not clear which foo() to call, A's or B's. We can
        disambiguate that by prepending the name of the class followed by two columns:
        A::foo(). */

        A::foo();
    }
};