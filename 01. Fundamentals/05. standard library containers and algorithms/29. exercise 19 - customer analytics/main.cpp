#include "user.h"

int main()
{
    std::map<std::string, UserAccount> users = {
        {"Alice", UserAccount{500, 15}},
        {"Bob", UserAccount{1000, 50}},
        {"Charlie", UserAccount{600, 17}},
        {"Donald", UserAccount{1500, 4}}
    };
    
    computeAnalytics(users);
    
    return 0;
}