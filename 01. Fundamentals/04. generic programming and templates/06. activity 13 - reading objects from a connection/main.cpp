/* The user is creating an online game which require to send
and receive its current state over an internet connection.
The application has several types of connections (TCP, UDP, socket)
each of them has a readNext() method which returns an std::array of 100 chars
containing the data inside the connection, and a writeNext() method
which takes an std::array of 100 characters which puts data into the connection

The aim is to be able to send the information
on the account of a user to the other users connected to the same online game,
so that they can see the user information
like their username and the level of their character */
#include "connection.cpp"

// make a tcp connection and then a udp connection
int main()
{
    std::cout << "serialize first user through tcp" << std::endl;
    // my solution
    TcpConnection tcpConnection;
    UserAccount firstAccount =
        readObjectFromConnection<UserAccount>(tcpConnection);
    writeObjectToConnection(firstAccount, tcpConnection);

    std::cout << "\nserialize second account through udp" << std::endl;
    // book's solution (changes ordering of connections)
    UdpConnection udpConnection;
    UserAccount secondAccount;
    writeObjectToConnection(secondAccount, udpConnection);
    UserAccount transmittedSecondAccount
        = readObjectFromConnection<UserAccount>(udpConnection);

    return 0;
}