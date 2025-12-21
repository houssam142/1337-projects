#include "iter.hpp"

void print(int x) { std::cout << x << " "; }

int main() {
    int arr[] = {1, 2, 3};
    const int arr1[] = {4, 5, 6};
    
    iter(arr, 3, print); std::cout << std::endl;
    iter(arr1, 3, print); std::cout << std::endl;
    return 0;
}
