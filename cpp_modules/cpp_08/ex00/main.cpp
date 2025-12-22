#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> arr;
		arr.push_back(4);
		arr.push_back(1);
		arr.push_back(2);
	
		easyfind(arr, 5);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
