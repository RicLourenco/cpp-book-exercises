#include <string>

/* Note to self: I made this class, and after all this, still don't know if it's
correctly written */
class Foo
{
    public:
        const auto &cref() const
        {
            return _cref;
        }

        auto &mref() const
        {
            return _mref;
        }

    private:
        const float _cref = 1.0f;
        int _mref = 1;
};

/* A const reference, denoted const auto&, has the ability to bind to anything. The
created variable is always immutable

If the const reference is bound to a temporary object, the lifetime of the
temporary will be extended to the lifetime of the reference */

auto func(const std::string& a, const std::string& b)
{
    const auto &str = a + b; // a + b returns a temporary
} // str goes out of scope, temporary will be destroyed

/* It's also possible to end up with a const reference by using auto& */

auto func2()
{
    auto foo = Foo { };
    auto &cref = foo.cref(); // cref is a constant reference
    auto &mref = foo.mref(); // mref is a mutable reference
}