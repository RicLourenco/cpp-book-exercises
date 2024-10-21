/* since c++11, there have been tools in the standard library to help with memory
management: smart pointers

smart pointers act like pointers (called raw pointers in this context) with
additional functionalities. We are going to look at two smart pointers from the
standard library: std::unique_ptr and std::shared_ptr. both remove the necessity to
call delete appropriately. They represent different ownership models. The owner of
an object is the code that determines the lifetime of the object – the part of the
code that decides when to create and when to destroy the object

Usually, ownership is associated with the scope a function or method, since the
lifetime of automatic variables is controlled by it */
void foo() {
    int number;
    do_action(number);
}
/* in this case, the scope of foo() owns the number object, and it will make sure
it is destroyed when the scope exits

Alternatively, classes might own objects when they are declared as value types
between the data members of the class. In that case, the lifetime of the object
will be the same as the lifetime of the class */
class A
{
    int number;
};

/* When managing objects in dynamic memory, ownership is not enforced by the
compiler anymore, but it is helpful to apply the concept of ownership to the
dynamic memory as well – the owner is who decides when to delete the object. A
function could be the owner of an object when the object is allocated with the new
call inside the function */
void foo() {
    int* number = new number();
    do_action(number);
    delete number;
}

/* Or a class might own it, by calling new in the constructor and storing the
pointer in its fields, and calling delete on it in the destructor */
class A
{
    public:
        A() : number(new int(0)) { }

        ~A() {
            delete number;
        }

        int* number;
};

/* But the ownership of dynamic objects can also be passed around. We looked at an
example earlier with the createLogger function. The function creates an instance of
Logger and then passes the ownership to the parent scope. Now, the parent scope is
in charge of making sure the object is valid until it is accessed in the program
and deleted afterward. Smart pointers allow us to specify the ownership in the type
of the pointer and make sure it is respected so that we do not have to keep track
of it manually anymore.

Note: Always use smart pointers to represent the ownership of objects. In a code
base, smart pointers should be the pointers that control the lifetime of objects,
and raw pointers, or regular pointers, are used only to reference objects */