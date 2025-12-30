#include "PmergeMe.hpp"

int jacobSthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobSthal(n - 1) + 2 * jacobSthal(n - 2);
}
