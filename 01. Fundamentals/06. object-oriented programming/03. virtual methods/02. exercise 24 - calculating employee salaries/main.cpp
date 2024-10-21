#include <iostream>
#include "department.h"

int main()
{
    Department department(1000, 1100);
    Employee employee;
    Manager manager;

    std::cout << "Employee salary: " << employee.getTotalComp(department) << "\n";
    std::cout << "Manager salary: " << manager.getTotalComp(department) << std::endl;
    
    return 0;
}