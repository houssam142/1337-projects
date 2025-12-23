#include "Span.hpp"

int main()
{
	try
	{
		std::vector<int> nums;

		nums.push_back(20);
		nums.push_back(21);
		nums.push_back(22);
		nums.push_back(23);
		nums.push_back(24);
		Span sp = Span(6);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumbers(nums.begin(), nums.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

