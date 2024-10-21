#include "matrix.h"

template<typename T, int R, int C>
std::string print(Matrix<T, R, C>& matrix) {
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            std::cout << matrix.get(r, c) << " ";
        }
        std::cout << "\n";
    }
    return "";
}

int main()
{
    Matrix<int, 3, 2> matrix({
        1, 2,
        3, 4,
        5, 6
    });

    std::cout << "Initial matrix: \n" << print(matrix) << std::endl;
    matrix.get(1, 1) = 7;
    std::cout << "Modified matrix: \n" << print(matrix) << std::endl;

    std::array<int, 2> vector = { 8, 9 };
    auto result = matrix.multiply(vector);

    std::cout << "Result of multiplication: { ";
    for(int i = 0; i < 3; i++) {
        if(i != 2) {
            std::cout << result[i] << ", ";
        } else {
            std::cout << result[i] << " }" << std::endl;
        }
    }

    return 0;
}