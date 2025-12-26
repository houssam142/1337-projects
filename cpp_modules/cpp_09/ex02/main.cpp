#include "PmergeMe.hpp"


int main(int ac, char **av)
{
	std::vector<int> vec;
	std::deque<int> deq;
	if (ac == 1)
		std::cerr << "Error\n";
	else
	{
		for (int i = 0; i < ac; i++)
			notSorted(av[i], vec, deq);
		std::cout << "before: ";
		displayVector(vec);
		
		std::cout << "After: ";
		sortVector(vec);
		displayVector(vec);
	}
	return 0;
}
