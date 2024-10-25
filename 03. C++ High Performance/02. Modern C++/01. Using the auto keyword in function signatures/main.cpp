// Old syntax with explicit types
struct Foo
{
    int val() const
    {
        return m_;
    }

    const int &cref() const
    {
        return m_;
    }

    int &mref()
    {
        return m_;
    }

    int m_{};
};

// New syntax with auto
struct Foo
{
    auto val() const
    {
        return m_;
    }

    auto &cref() const
    {
        return m_;
    }

    auto &mref()
    {
        return m_;
    }

    int m_{};
};

/* The auto syntax can be used both with and without trailing return type. The
trailing return is necessary if you put the function definition in the .cpp file
instead of in the header declaration. Look at the three following return types */

// Value: 
auto val() const // a) auto, deduced type
auto val() const -> int // b) auto with type
int val() const // c) explicit type


// Const reference:
auto& cref() const // a) auto, deduced type
auto cref() const -> const int& // b) auto, trailing type
const int& cref() const // c) explicit type

// Mutable reference:
auto& mref() // a) auto, deduced type
auto mref() -> int& // b) auto, trailing type
int& mref() // c) explicit type

