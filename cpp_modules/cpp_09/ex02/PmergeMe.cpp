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

void sortVector(std::vector<int>& vec)
{
    std::vector<int> _winners;
    std::vector<int> _losers;
    if (vec.size() == 1)
        return ;
    bool struggler = (vec.size() % 2 == 1);
    int num = 0;
    if (struggler)
    {
        num = vec[vec.size() - 1];
        vec.pop_back();
    }
    for (unsigned int i = 0; i < vec.size(); i+=2)
    {
        if (vec[i] >= vec[i + 1])
        {
            _winners.push_back(vec[i]);
            _losers.push_back(vec[i + 1]);
        }
        else if (vec[i + 1] >= vec[i])
        {
            _winners.push_back(vec[i + 1]);
            _losers.push_back(vec[i]);
        }
    }
    if (struggler)
        _losers.push_back(num);
    sortVector(_winners);
}
