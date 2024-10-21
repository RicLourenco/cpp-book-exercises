#include "list.h"

int main()
{
    // initialize a list
    List list = List();

    // add several items to the List
    list.Insert(0, 21);
    list.Insert(1, 47);
    list.Insert(2, 87);
    list.Insert(3, 35);
    list.Insert(4, 92);

    // print current List
    std::cout << "List elements:\n";
    for (int i = 0; i < list.Count(); i++) {
        std::cout << list.Get(i) << " ";
    }
    std::cout << "\n\n";

    // Insert several items in the middle of the List
    list.Insert(2, 25);
    list.Insert(2, 71);

    std::cout << "New List elements:\n";
    for(int i = 0; i < list.Count(); ++i)
    {
        std::cout << list.Get(i) << " ";
    }
    std::cout << "\n\n";

    // Search value 71
    std::cout << "Search element 71\n";
    int result = list.Search(71);
    if(result == -1) {
        std::cout << "71 is not found";
    } else {
        std::cout << "71 is found at index " << result;
    }
    std::cout << "\n\n";

    // Remove index 2
    std::cout << "Remove element at index 2\n";
    list.Remove(2);
    std::cout << "\n";

    // Print the List again
    std::cout << "New List elements:\n";
    for(int i = 0; i < list.Count(); ++i) {
        std::cout << list.Get(i) << " ";
    }
    std::cout << "\n\n";

    // Search value 71 again
    std::cout << "Search element 71 again\n";
    result = list.Search(71);
    if(result == -1) {
        std::cout << "71 is not found";
    } else {
        std::cout << "71 is found at index " << result;
    }
    std::cout << std::endl;

    return 0;
}