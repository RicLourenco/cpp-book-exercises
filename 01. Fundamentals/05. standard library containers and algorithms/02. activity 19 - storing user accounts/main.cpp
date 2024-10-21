#include <iostream>
#include <array>
#include <vector>

template<typename T, int N>
std::array<T, N> initializeArray() {
    std::array<T, N> arr;
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = 0;
    }
    return arr;
}

template<typename T>
std::vector<T> initializeVector() {
    std::vector<T> vec;
    vec.reserve(100);
    for(int i = 0; i < vec.capacity(); i++) {
        vec.insert(vec.begin() + i, 0);
    }
    return vec;
}

int main()
{
    auto accountsContainer = initializeArray<int, 10>();
    accountsContainer.front() += 100;
    accountsContainer.back() += 100;
    for(int i = 0; i < accountsContainer.size(); i++) {
        std::cout << "account array " << i + 1 << " balance: " << accountsContainer[i] << std::endl;
    }

    auto accountsVector = initializeVector<int>();
    for(int i = 0; i < accountsVector.size(); i++) {
        std::cout << "account vector " << i + 1 << " balance: " << accountsVector.at(i) << std::endl;
    }
    accountsVector.resize(10);
    for(int i = 0; i < accountsVector.size(); i++) {
        std::cout << "account vector " << i + 1 << " balance: " << accountsVector.at(i) << std::endl;
    }

    return 0;
}