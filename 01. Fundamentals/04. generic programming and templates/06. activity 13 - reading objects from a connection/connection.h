#include <iostream>
#include <array>

template<typename Object, typename Connection>
Object readObjectFromConnection(Connection& con) {
    std::array<char, 100> data = con.readNext();
    return Object::deserialize(data);
}

template<typename Object, typename Connection>
void writeObjectToConnection(const Object& obj, Connection& con) {
    std::array<char, 100> data;

    // my solution
    // data = obj.serialize(obj);

    // book's solution (it's a static method)
    data = Object::serialize(obj);

    con.writeNext(data);
}