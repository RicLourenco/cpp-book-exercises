#include <iostream>
#include "linkedList.h"
#include "node.h"

int main()
{
    LinkedList<int> linkedList = LinkedList<int>();
    
    linkedList.InsertHead(43);
    
    linkedList.InsertHead(76);
    
    linkedList.InsertTail(15);
    
    linkedList.InsertTail(44);
    
    std::cout << "First Printed:" << std::endl;
    linkedList.PrintList();
    std::cout << std::endl;
    
    linkedList.Insert(4, 100);
    
    linkedList.Insert(3, 48);
    
    linkedList.Insert(0, 22);
    
    std::cout << "Second Printed:" << std::endl;
    linkedList.PrintList();
    std::cout << std::endl;
    
    std::cout << "Get value of the second index:" << std::endl;
    Node<int> *get = linkedList.Get(2);

    if(get != NULL) {
        std::cout << get->Value;
    } else {
        std::cout << "not found";
    }

    std::cout << std::endl << std::endl;
    
    std::cout << "The position of value 15:" << std::endl;
    int srch = linkedList.Search(15);
    std::cout << srch << std::endl << std::endl;
    
    std::cout << "Remove the first element:" << std::endl;
    linkedList.Remove(0);
    
    linkedList.PrintList();
    std::cout << std::endl;
    
    std::cout << "Remove the fifth element:" << std::endl;
    linkedList.Remove(4);
    
    linkedList.PrintList();
    std::cout << std::endl;
    
    std::cout << "Remove the tenth element:" << std::endl;
    linkedList.Remove(9);
    
    linkedList.PrintList();
    std::cout << std::endl;
    return 0;
}