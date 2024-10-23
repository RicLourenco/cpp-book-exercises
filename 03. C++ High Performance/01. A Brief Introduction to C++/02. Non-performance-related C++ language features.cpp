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