#include <iostream>
#include <array>

class Map_Position
{
    public:
        Map_Position(size_t array_size) {
            this -> map_position = allocate_memory(array_size);
            std::cout << "map allocated\n";
        }

        ~Map_Position() {
            release_memory(this -> map_position);
            std::cout << "map released\n" << std::endl;
        }

        int get_map_position(int index) {
            return this -> map_position[index];
        }

        void add_coordinate(int index, int value) {
            this -> map_position[index] = value;
        }
    
    private:
        int* allocate_memory(size_t array_size) {
            return new int[array_size];
        }

        void release_memory(int* array_ptr) {
            delete [] array_ptr;
        }
        
        int* map_position;
};

int main()
{
    Map_Position map(3);
    {
        map.add_coordinate(0, 21);
        map.add_coordinate(1, 2);
        map.add_coordinate(2, 3123);

        for (int i = 0; i < 3; i++) {
            std::cout << "map coordinate " << i <<": " << map.get_map_position(i) << "\n";
        }
    }

    std::cout << "program end\n";
    return 0;
}