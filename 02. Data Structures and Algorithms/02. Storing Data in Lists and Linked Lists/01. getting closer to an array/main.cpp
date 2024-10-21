#include <iostream>

void initArr()
{
    // initialize an array
    int arr[] = { 21, 47, 87, 35, 92 };

    // access each element
    std::cout << "array elements: ";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // manipulate several elements
    arr[2] = 30;
    arr[3] = 64;

    // access each element again
    std::cout << "array elements: ";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void arrPtr()
{
    /* There's an interesting fact about arrays: we can access the array's element
    using a pointer. As you may know, a pointer is a variable that holds the
    address instead of the value. And, since we discussed earlier that each element
    in the array has its own address, we can access each array's element using its
    address. To use a pointer as an array, we need to initialize it to hold an
    array:
    int * ptr = new int[5] { 21, 47, 87, 35, 92 };

    After the preceding initialization, we have a pointer named ptr that points to
    the first element of an array containing five elements. However, the ptr
    variable holds the first array's element address at the start. To access the
    next address, we can increment the ptr variable (ptr++) so that it will point
    to the next element. To get the value of the currently selected address, we can
    use a wildcard symbol before the pointer name (*ptr):
    std::cout << *ptr << std::endl;
    std::cout << ptr << std::endl;

    The former statement in the preceding code snippet will print out the value
    that the pointer points to, and the latter will print the address that the
    pointer holds. Interestingly, since we initialize the ptr pointer as an array,
    we can access the value of each element and the address as well by its index:
    std::cout << ptr[i] << std::endl;
    std::cout << &ptr[i] << std::endl;

    In the preceding code snippet, the former line will print the value of the
    selected element and the latter will print the address of the selected element
    (since we added the apostrophe symbol before the pointer name—&ptr[i]) */

    // Initialize the array length
    int arrLength = 5;

    // Initialize a pointer
    // to hold an array
    int * ptr = new int[arrLength] { 21, 47, 87, 35, 92 };

    // Display each element value
    // by incrementing the pointer (ptr++)
    std::cout << "Using pointer increment" << std::endl;
    std::cout << "Value\tAddress" << std::endl;
    while (*ptr) {
        std::cout << *ptr << "\t";
        std::cout << ptr << std::endl;
        ptr++;
    }

    // Since we have moved forward the pointer five times
    // we need to move it back
    ptr = ptr - 5;

    // Display each element value
    // by accessing pointer index (ptr[])
    std::cout << "Using pointer index" << std::endl;
    std::cout << "Value\tAddress" << std::endl;
    for (int i = 0; i < arrLength; ++i) {
        std::cout << ptr[i] << "\t";
        std::cout << &ptr[i] << std::endl;
    }

}

int main()
{
    initArr();
    arrPtr();
    return 0;
}