#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_extractWorth("data.csv");
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& eq)
{
	return *this;
}

bool	BitcoinExchange::checkDates(std::string line)
{
	if (line[4] != '-' || line[7] != '-' || line.length() != 4)
		return false;
	return true;
}

void BitcoinExchange::_extractWorth(const std::string file)
{
	std::ifstream infile(file.c_str());
	std::string input;

	std::getline(infile, input);
	while (std::getline(infile, input))
	{
		if (!checkDates(input))
			throw std::invalid_argument("Error");
	}
}

BitcoinExchange::~BitcoinExchange() {}
