#include <iostream>
#include <array>
#include <string>

template<typename T, int R, int C>
class Matrix
{
    private:
        std::array<T, R * C> data;

    public:
        Matrix() : data({ }) { }

        Matrix(std::array<T, R * C> initialValues) : data(initialValues) { }

        T& get(int row, int col) {
            if (row >= R || col >= C) {
                std::abort();
            }

            return data[row * C + col];
        }

        // bonus: multiply a matrix by a vector
        std::array<T, R> multiply(std::array<T, C>& vector) {
            std::array<T, R> result = { };
            for(int r = 0; r < R; r++) {
                for(int c = 0; c < C; c++) {
                    result[r] += get(r, c) * vector[c];
                }
            }
            return result;
        }
};

// this operator overloader doesn't work
/* template<typename T, size_t R, size_t C>
std::ostream& operator<<(std::ostream& os, Matrix<T, R, C> matrix) {
    os << "\n";
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            os << matrix.get(r, c) << " ";
        }
        os << "\n";
    }
    return os;
} */