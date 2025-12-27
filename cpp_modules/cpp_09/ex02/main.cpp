#include <iomanip>
#include "PmergeMe.hpp"

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
			if (!parseAndAddNumber(av[i], vec, deq))
				return 1;
		}
		std::cout << "before: ";
		displayVector(vec);
		
		gettimeofday(&start, NULL);

		sortVector(vec);
		gettimeofday(&end, NULL);
		std::cout << "After: ";
		displayVector(vec);
		double vecTime = (static_cast<double>(end.tv_sec) - static_cast<double>(start.tv_sec)) * 1000000.0 + (static_cast<double>(end.tv_usec) - static_cast<double>(start.tv_usec));
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime << " us\n";
		gettimeofday(&start, NULL);

		sortDeque(deq);

		gettimeofday(&end, NULL);
		double deqTime = (static_cast<double>(end.tv_sec) - static_cast<double>(start.tv_sec)) * 1000000.0 + (static_cast<double>(end.tv_usec) - static_cast<double>(start.tv_usec));
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqTime << " us\n";
	}
	return 0;
}
