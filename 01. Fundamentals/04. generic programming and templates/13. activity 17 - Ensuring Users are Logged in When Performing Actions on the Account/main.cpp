#include "user.h"

int main()
{
    UserIdentifier user { };
    login(user);

    std::vector<Item> items = {
        { "Item1" },
        { "Item2" },
        { "Item3" }
    }; // might be very long
    execute_on_user_cart(user, add_items, std::move(items));

    logout(user);
    execute_on_user_cart(user, remove_item, Item { "Item1" });

    return 0;
}