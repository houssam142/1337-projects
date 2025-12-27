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

bool    parseAndAddNumber(std::string name, std::vector<int>& vec, std::deque<int>& deq)
{
    char *leftOver = NULL;
    long num = std::strtol(name.c_str(), &leftOver, 10);
    if (*leftOver != '\0' || leftOver == name.c_str() || num < 0)
    {
        std::cerr << "Error: negative number\n";
        return false;
    }
    vec.push_back(num);
    deq.push_back(num);
    return true;
}

unsigned int jacobSthal(unsigned int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return jacobSthal(n - 1) + 2 * jacobSthal(n - 2);
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
    for (unsigned int i = 0; i < _losers.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(_winners.begin(), _winners.end(), _losers[i]);
        _winners.insert(pos, _losers[i]);
    }
    vec = _winners;
}

void sortDeque(std::deque<int>& deq)
{
    std::deque<int> _winners;
    std::deque<int> _losers;
    if (deq.size() == 1)
        return ;
    bool struggler = (deq.size() % 2 == 1);
    int num = 0;
    if (struggler)
    {
        num = deq[deq.size() - 1];
        deq.pop_back();
    }
    for (unsigned int i = 0; i < deq.size(); i+=2)
    {
        if (deq[i] >= deq[i + 1])
        {
            _winners.push_back(deq[i]);
            _losers.push_back(deq[i + 1]);
        }
        else if (deq[i + 1] >= deq[i])
        {
            _winners.push_back(deq[i + 1]);
            _losers.push_back(deq[i]);
        }
    }
    if (struggler)
        _losers.push_back(num);
    sortDeque(_winners);
    for (unsigned int i = 0; i < _losers.size(); i++)
    {
        std::deque<int>::iterator pos = std::lower_bound(_winners.begin(), _winners.end(), _losers[i]);
        _winners.insert(pos, _losers[i]);
    }
    deq = _winners;
}
