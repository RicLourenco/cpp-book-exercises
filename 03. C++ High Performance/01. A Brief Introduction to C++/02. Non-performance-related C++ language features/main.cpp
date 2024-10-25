/* Value semantics: C++ supports both value semantics and reference semantics:
Value semantics pass objects by value. Reference semantics pass objects by
reference. Value semantics is the default in C++, to use reference semantics we
need to use pointers and references. The C++ type system gives us the ability to
explicitly state the ownership of an object, example: */

#include <set>
#include <string>

// C++
class Bagel
{
    public:
        Bagel(const std::set<std::string>& ts) : toppings_(ts) {}
    private:
        std::set<std::string> toppings_;
};

// Java
// class Bagel
// {
//     public Bagel(ArrayList<String> ts)
//     {
//         toppings_ = ts;
//     }

//     private ArrayList<String> toppings_;
// }

/* In the C++ version, the programmer states that the toppings are completely
encapsulated by the Bagel class. Had the programmer intended the topping list to be
shared among several bagels, it would have been declared as a pointer of some kind:
std::shared_ptr, if the ownership is shared among several bagels, or a
std::weak_ptr, if someone else owns the topping list and is supposed to modify it
as the program execute

In Java, objects references each other with shared ownership. Therefore, it's not
possible to distinguish whether the topping list is intended to be shared among
several bagels or not, or whether it is handled somewhere else or if it is, as in
most cases, completely owned by the Bagel class

Compare the following functions; as every object is shared by default in Java (and
most other languages), programmers have to take precautions for subtle bugs such as
this */

// The bagels don't share toppings
void example_cpp()
{
    auto t = std::set<std::string>{};
    t.insert("salt");
    auto a = Bagel{t};
    // 'a' is not affected
    // when adding pepper
    t.insert("pepper");
    // 'a' will have salt
    // 'b' will have salt & pepper
    auto b = Bagel{t};
    // No bagel is affected
    t.insert("oregano");
}

// The bagels subtly share toppings
// TreeSet<String> t = new
// TreeSet<String>();
// t.add("salt");
// Bagel a = new Bagel(t);
// // Now 'a' will subtly
// // also have pepper
// t.add("pepper");
// // 'a' and 'b' share the
// // toppings in 't'
// Bagel b = new Bagel(t);
// // Both bagels subtly
// // also have "oregano"
// toppings.add("oregano");

/* Const correctness

An example of how we can use const member functions to prevent unintentional
modifications of objects. In the following Person class, the member function age()
is declared const and is therefore not allowed to mutate the Person object; whereas
set_age() mutates the object and cannot be declared const */
class Person
{
    public:
        auto age() const
        {
            return _age;
        }

        auto set_age(int age) 
        {
            _age = age;
        }

    private:
        int _age {};
};

/* It's also possible to distinguish between returning mutable and immutable
references to members. In the following Team class, the member function leader()
const returns an immutable Person; whereas leader() returns a Person object that
may be mutated */
class Team
{
    public:
        auto& leader() const
        {
            return _leader;
        }

        auto& leader()
        {
            return _leader;
        }

    private:
        Person _leader {};
};

/* Now let's see how the compiler can help us find errors when we try to mutate
immutable objects. In the following example, the function argument teams is
declared const, explicitly showing that this function is not allowed to modify
them */
auto non_mutating_func(const std::vector<Team>& teams)
{
    auto tot_age = int { 0 };
    
    // Compiles, both leader() and age() are declared const
    for(const auto& team: teams) {
        tot_age += team.leader().age();
    }

    // Doesn't compile, set_age() requires a mutable object
    for(auto& team: teams) {
        team.leader().set_age(20);
    }

    /* If we want to write a function which can mutate the teams object we simply
    remove const in the parameters. This signals to the caller that this function may mutate the
    teams ...(std::vector<Team>& teams)... */
}