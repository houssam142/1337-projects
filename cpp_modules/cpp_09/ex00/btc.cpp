#include "BitcoinExchange.hpp"

void BitcoinExchange::_extractBitcoins(const std::string arg)
{
	std::ifstream infile(arg.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: file not open");
	std::string line;
	std::getline(infile, line);
	if (line == "date | value")
		throw std::invalid_argument("Error: bad input");
	while (std::getline(infile, line))
	{
		std::string date = line.substr(0, line.find(' '));
		if (date[4] != '-' || date[7] != '-' || date.length() != 10)
			throw std::invalid_argument("Error: bad input");
	}
}
