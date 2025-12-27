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

int jacobSthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return jacobSthal(n - 1) + 2 * jacobSthal(n - 2);
}

void sortVector(std::vector<int>& vec)
{
    if (vec.size() == 1)
        return ;
    std::vector<std::pair<int, int> > _pair;
    std::vector<int> _winners;
    std::vector<int> _losers;
    bool struggler = (vec.size() % 2 == 1);
    int num = -1;
    if (struggler)
    {
        num = vec.back();
        vec.pop_back();
    }
    for (unsigned int i = 0; i < vec.size(); i+=2)
    {
        _pair.push_back(std::make_pair(vec[i], vec[i + 1]));
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
    sortVector(_winners);

    if (!_losers.empty())
        _winners.insert(std::lower_bound(_winners.begin(), _winners.end(), _losers[0]), _losers[0]);
    int k = 3;
    int end = 1;
    int size = _losers.size();
    for (int prev = 1; prev < size; prev = end)
    {
        end = std::min(jacobSthal(k), size);
        for (int j = end - 1; j >= prev; j--)
        {
            std::vector<int>::iterator limit = _winners.begin() + j + prev;
            if (limit > _winners.end())
                limit = _winners.end();
            std::vector<int>::iterator pos = std::lower_bound(_winners.begin(), limit, _losers[j]);
            _winners.insert(pos, _losers[j]);
        }
        k++;
    }
    if (struggler)
        _winners.insert(std::lower_bound(_winners.begin(), _winners.end(), num), num);
    vec = _winners;
}

void sortDeque(std::deque<int>& deq)
{
    std::deque<std::pair<int, int> > _pair;
    std::deque<int> _winners;
    std::deque<int> _losers;
    if (deq.size() == 1)
        return ;
    bool struggler = (deq.size() % 2 == 1);
    int num = -1;
    if (struggler)
    {
        num = deq[deq.size() - 1];
        deq.pop_back();
    }
    for (unsigned int i = 0; i < deq.size(); i+=2)
    {
        _pair.push_back(std::make_pair(deq[i], deq[i + 1]));
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
    sortDeque(_winners);
    if (!_losers.empty())
        _winners.insert(std::lower_bound(_winners.begin(), _winners.end(), _losers[0]), _losers[0]);

    int k = 3;
    int end = 1;
    int size = _losers.size();
    for (int prev = 1; prev < size; prev = end)
    {
        end = std::min(jacobSthal(k), size);
        for (int j = end - 1; j >= prev; j--)
        {
            std::deque<int>::iterator limit = _winners.begin() + j + prev;
            if (limit > _winners.end())
                limit = _winners.end();
            std::deque<int>::iterator pos = std::lower_bound(_winners.begin(), _winners.end(), _losers[j]);
            _winners.insert(pos, _losers[j]);
        }
        k++;
    }
    if (struggler)
        _winners.insert(std::lower_bound(_winners.begin(), _winners.end(), num), num);
    deq = _winners;
}
