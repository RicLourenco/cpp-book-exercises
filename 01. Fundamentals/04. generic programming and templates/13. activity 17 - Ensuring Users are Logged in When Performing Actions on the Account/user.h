#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

struct Item
{
    std::string item;

    Item(std::string itemName) {
        item = itemName;
    }

    bool operator== (const Item& obj) {
        return obj.item == item;
    }
};

struct Cart
{
    std::vector<Item> items;
};

struct UserIdentifier
{
    int userId = 0;
    Cart cart;
};

void login(UserIdentifier& user) {
    user.userId = 0;
}

void logout(UserIdentifier& user) {
    user.userId = 1;
}

bool isLoggedIn(const UserIdentifier& user) {
    return user.userId % 2 == 0;
}

Cart getUserCart(const UserIdentifier& user) {
    return user.cart;
}

template<typename Action, typename Parameter>
void execute_on_user_cart(UserIdentifier& user, Action action, Parameter&& parameter) {
    if (isLoggedIn(user)) {
        // Cart cart = getUserCart(user);
        action(user.cart, std::forward<Parameter>(parameter));
    } else {
        std::cout << "The user is not logged in" << std::endl;
    }
}

void add_items(Cart& cart, std::vector<Item> items) {
    cart.items.insert(cart.items.end(), items.begin(), items.end());
    std::cout << items.size() << " items added" << std::endl;
}

void remove_item(Cart& cart, Item item) {
    std::vector<Item>::iterator location = std::find(cart.items.begin(), cart.items.end(), item);
    if (location != cart.items.end()) {
        std::cout << item.item;
        cart.items.erase(location);
        std::cout << "Item removed" << std::endl;
    }
}