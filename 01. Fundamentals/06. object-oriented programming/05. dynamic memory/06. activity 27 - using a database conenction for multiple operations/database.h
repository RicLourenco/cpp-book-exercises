#include <future>
#include <memory>
#include <iostream>

struct DatabaseConnection { };

void updateOrderList(DatabaseConnection& connection) {
    std::cout << "Updating order list" << std::endl;
}

void scheduleOrderProcessing(DatabaseConnection& connection) {
    std::cout << "Schedule order processing" << std::endl;
}

/* We need to get a copy of the shared_ptr so it stays alive until this function
finishes */
void updateWithConnection(std::shared_ptr<DatabaseConnection> connection) {
    updateOrderList(*connection);
}

/* We need to get a copy of the shared_ptr so it stays alive until this
function finishes. */
void scheduleWithConnection(std::shared_ptr<DatabaseConnection> connection) {
    scheduleOrderProcessing(*connection);
}