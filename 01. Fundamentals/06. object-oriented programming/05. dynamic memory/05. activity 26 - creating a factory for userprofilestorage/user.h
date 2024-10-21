#include <memory>
#include "../../04. interfaces in c++/02. activity 25 - retrieving user information/user.h"

class UserProfileStorageFactory
{
    public:
        std::unique_ptr<UserProfileStorage> create() const {
            return std::make_unique<UserProfileCache>();
        }
};

void getUserProfile(const UserProfileStorageFactory& storageFactory) {
    std::unique_ptr<UserProfileStorage> storage = storageFactory.create();
    UserId user;
    storage -> getUserProfile(user);
    // The storage is automatically destroyed
}