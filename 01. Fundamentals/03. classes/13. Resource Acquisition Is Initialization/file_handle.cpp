#include <iostream>
#include <fstream>

class file_handle
{
    public:
        file_handle(std::ofstream& stream, const char* filepath) : _stream(stream) {
            _stream.open(filepath);
            std::cout << "file opened" << std::endl;
        }

        ~file_handle() {
            _stream.close();
            std::cout << "file closed" << std::endl;

            std::remove("some path");
            std::cout << "file deleted" << std::endl;
        }

    private:
        std::ofstream& _stream;
};

int main()
{
    std::ofstream stream;
    {
        file_handle my_file(stream, "some path");
        //do_something_with_file(my_file);
    }

    return 0;
}