int main()
{
    // Examples
    auto i = 0;
    auto x = Foo{};
    auto y = create_object();
    auto z = std::mutex{};

    /* With copy elision guarantees introduced in C++17, the statement
    auto x = Foo{} is identical to Foo x{}. That is, the language guarantees that
    there is no temporary object that needs to be moved or copied in this case.
    This means that we can now use the left-to-right initialization style without
    worrying about performance and we can also use it for non-moveable/non-copyable
    types */

    return 0;
}