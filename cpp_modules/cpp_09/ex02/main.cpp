#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::vector<int> vec;
	std::deque<int> deq;
	struct timeval mic;
	if (ac == 1)
		std::cerr << "Error\n";
	else
	{
		for (int i = 0; i < ac; i++)
			notSorted(av[i], vec, deq);
		std::cout << "before: ";
		displayVector(vec);
		
		gettimeofday(&mic, NULL);
		std::cout << "After: ";
		double sVecTime = static_cast<double>(mic.tv_sec) * 1000000.0 + static_cast<double>(mic.tv_usec);
		sortVector(vec);
		gettimeofday(&mic, NULL);
		double eVecTime = static_cast<double>(mic.tv_sec) * 1000000.0 + static_cast<double>(mic.tv_usec);
		displayVector(vec);
		std::cout << "Time to process a range of 5 elements with std::vector: " << eVecTime - sVecTime << " us\n";
	}
	return 0;
}
