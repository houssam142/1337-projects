#include "PmergeMe.hpp"


template <typename T>
bool    parseAndAddNumber(std::string name, T& cont)
{
    char *leftOver = NULL;
    long num = std::strtol(name.c_str(), &leftOver, 10);
    if (*leftOver != '\0' || leftOver == name.c_str() || num < 0)
    {
        std::cerr << "Error\n";
        return false;
    }
    typename T::iterator it = std::find(cont.begin(), cont.end(), num);
    if (it != cont.end())
    {
        std::cerr << "Found duplicate" << '\n';
        return false;
    }
	cont.push_back(num);
    return true;
}

template <typename T>
void display(const T& v)
{
    typename T::const_iterator it = v.begin();
    for (; it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T, typename Y>
void FordJohnson(T& vec)
{
    if (vec.size() == 1)
        return ;
    Y _pair;
    bool struggler = (vec.size() % 2 == 1);
    T _winners;
    int num = -1;
    if (struggler)
    {
        num = vec.back();
        vec.pop_back();
    }
    for (unsigned int i = 0; i < vec.size(); i+=2)
    {
        if (vec[i] >= vec[i + 1])
            _pair.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            _pair.push_back(std::make_pair(vec[i + 1], vec[i]));
        _winners.push_back(_pair.back().first);
    }
    FordJohnson<T, Y>(_winners);

    T& _mainChain = _winners;
    T _losers;
    for (size_t i = 0; i < _winners.size(); i++)
    {
        for (size_t j = 0; j < _pair.size(); j++)
        {
            if (_winners[i] == _pair[j].first)
            {
                _losers.push_back(_pair[j].second);
                _pair.erase(_pair.begin() + j);
                break;
            }
        }
    }
    
    _mainChain.insert(_mainChain.begin(), _losers[0]);
    int prev_end = 1;
    int curr_end = 1;
    int k = 3;
    int size = static_cast<int>(_losers.size());
    while (prev_end < size)
    {
        curr_end = jacobSthal(k);
        if (curr_end > size) curr_end = size;
        for (int j = curr_end - 1; j >= prev_end; j--)
        {
            int limit_idx = std::min(static_cast<int>(_mainChain.size()), j + curr_end);

            typename T::iterator limit = std::find(_mainChain.begin(), _mainChain.end(), limit_idx);
            typename T::iterator pos = std::lower_bound(_mainChain.begin(), limit, _losers[j]);
            _mainChain.insert(pos, _losers[j]);
        }
        prev_end = curr_end;
        k++;
    }
    if (struggler)
        _mainChain.insert(std::lower_bound(_mainChain.begin(), _mainChain.end(), num), num);
    vec = _mainChain;
}

int main(int ac, char **av)
{
	std::vector<int> vec;
	std::deque<int> deq;
	struct timeval start, end;
	if (ac == 1)
		std::cerr << "Error\n";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			if (!parseAndAddNumber(av[i], vec) || !parseAndAddNumber(av[i], deq))
				return 1;
		}
		std::cout << "before: ";
		display(vec);
		
		gettimeofday(&start, NULL);

		FordJohnson<std::vector<int>, std::vector<std::pair<int, int> > >(vec);
		gettimeofday(&end, NULL);
		std::cout << "After: ";
		display(vec);
		double vecTime = (static_cast<double>(end.tv_sec) - static_cast<double>(start.tv_sec)) * 1000000.0 + (static_cast<double>(end.tv_usec) - static_cast<double>(start.tv_usec));
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime << " us\n";
		gettimeofday(&start, NULL);

		FordJohnson<std::deque<int>, std::deque<std::pair<int, int> > >(deq);

		gettimeofday(&end, NULL);
		double deqTime = (static_cast<double>(end.tv_sec) - static_cast<double>(start.tv_sec)) * 1000000.0 + (static_cast<double>(end.tv_usec) - static_cast<double>(start.tv_usec));
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqTime << " us\n";
	}
	return 0;
}
