// take the matrix from activity 15 and simplify its end use
#include "matrix.h"

template<int R, int C, typename T = int, typename Multiply = std::multiplies<T>>
std::string print(Matrix<R, C, T, Multiply>& matrix) {
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
    Matrix<3, 2, int, std::plus<int>> matrixAdd({
        1, 2,
        3, 4,
        5, 6
    });

    std::cout << "Initial matrix: \n" << print(matrixAdd) << std::endl;
    // matrixAdd.get(1, 1) = 7;
    // std::cout << "Modified matrix: \n" << print(matrixAdd) << std::endl;

    std::array<int, 2> vector = { 8, 9 };
    auto result = matrixAdd.multiply(vector);

    std::cout << "Result of multiplication (with +): { ";
    for(int i = 0; i < 3; i++) {
        if(i != 2) {
            std::cout << result[i] << ", ";
        } else {
            std::cout << result[i] << " }" << std::endl;
        }
    }

    return 0;
}