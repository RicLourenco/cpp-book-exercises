#include "connection.h"

class UserAccount
{
    public:
        static std::array<char, 100> serialize(const UserAccount& account) {
            std::cout << "the user account has been serialized." << std::endl;
            return std::array<char, 100>();
        }

        static UserAccount deserialize(const std::array<char, 100>& blob) {
            std::cout << "the user account has been deserialized." << std::endl;
            return UserAccount();
        }
};

class TcpConnection
{
    public:
        std::array<char, 100> readNext() {
            std::cout << "the data has been read" << std::endl;
            return std::array<char, 100>();
        }

        void writeNext(const std::array<char, 100>& blob) {
            std::cout << "the data has been written" << std::endl;
        }
};

// just copied the TcpConnection class, gotta be a better way to do this
class UdpConnection
{
    public:
        std::array<char, 100> readNext() {
            std::cout << "the data has been read" << std::endl;
            return std::array<char, 100>();
        }

        void writeNext(const std::array<char, 100>& blob) {
            std::cout << "the data has been written" << std::endl;
        }
};