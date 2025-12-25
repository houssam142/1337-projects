#include "PmergeMe.hpp"

void displayVector(const std::vector<int>& v)
{
    std::vector<int>::const_iterator it = v.begin();
    for (; it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void displayDeque(const std::deque<int>& d)
{
    std::deque<int>::const_iterator it = d.begin();
    for (; it != d.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void notSorted(std::string name, std::vector<int>& vec, std::deque<int>& deq)
{
    char *leftOver = NULL;
    long num = std::strtol(name.c_str(), &leftOver, 10);
    if (*leftOver != '\0' || leftOver == name.c_str())
        return ;
    vec.push_back(num);
    deq.push_back(num);
}
