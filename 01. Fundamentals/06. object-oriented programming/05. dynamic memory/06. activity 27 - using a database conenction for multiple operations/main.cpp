#include "database.h"

int main()
{
    std::shared_ptr<DatabaseConnection> connection =
        std::make_shared<DatabaseConnection>();
    
    std::cout << "Updating order and scheduling order processing in parallel" << std::endl;
    std::async(std::launch::async, updateWithConnection, connection);
    std::async(std::launch::async, scheduleWithConnection, connection);
}