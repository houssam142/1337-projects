#include "ScalarConverter.hpp" 

int main(int ac, char **av)
{
	if (ac != 2)
		return std::cerr << "Invalid arguments\n", 1;
	std::string lit = av[1];
	ScalarConverter::convert(av[1]);
	return 0;
}
