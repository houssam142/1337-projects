#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	try
	{
		if (ac != 2)
			throw std::invalid_argument("Error");
		BitcoinExchange bitcoin;	
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
