#include "iter.hpp"

void print(int x) { std::cout << x << " "; }
void increment(int& x) { x++; }

template<typename T>
struct Printer {
    void operator()(T x) { std::cout << x << " "; }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    std::cout << "Before: ";
    iter(arr, 5, print); std::cout << std::endl;
    
    iter(arr, 5, increment);
    
    std::cout << "After: ";
    iter(arr, 5, print); std::cout << std::endl;
    
    return 0;
}
