/* Let's put the std::function to use in something that resembles a real-world
example. If we create a Button class, we can use the std::function to store the
action corresponding to clicking the buttons, so that when we call the on_click()
member function, the corresponding code is executed */

#include <iostream>
#include <functional>
#include <vector>

/* We can declare the Button class like this */
class Button
{
    public:
        Button(std::function<void(void)> click) : _on_click { click } { }

        auto on_click() const
        {
            _on_click();
        }

    private:
        std::function<void(void)> _on_click { };
};

/* We can then use it to create a multitude of buttons with different actions. As
each button still has the same type, they can also be stored in a container */
auto make_buttons()
{
    auto beep_button = Button([beep_count = 0]() mutable
    {
        std::cout << "Beep: " << beep_count << "! ";
        ++beep_count;
    });

    auto bop_button = Button([]
    {
        std::cout << "Bop. ";
    });

    auto silent_button = Button([] { });

    auto buttons = std::vector<Button>
    {
        beep_button,
        bop_button,
        silent_button
    };

    return buttons;
}

/* Iterating the list by executing the on_click() on each button will execute the
corresponding function */
void click_buttons()
{
    auto buttons = make_buttons();

    for(const auto &b: buttons) {
        b.on_click();
    }
    buttons.front().on_click();
    /* Output: "Beep: 0! Bop. Beep: 1!" */
}

/* As you can see, the on_click() member function is a const function, yet it is
mutating the member variable on_click_ by increasing the beep_count_. This might
seem like it breaks const correctness rules, as a const member function of Button
is allowed to call a mutating function on one of its class members. The reason it
is allowed is the same reason that member pointers are allowed to mutate their
pointed-to value in a const context. Later on in this chapter we will discuss how
to propagate constness for pointer data members */

int main()
{
    click_buttons();

    return 0;
}