#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_extractWorth("data.csv");
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	(void)copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& eq)
{
	(void)eq;
	return *this;
}

bool	checkFormat(int year, int month, int day)
{
	int maxDays;
	if (year < 2009 || month < 1 || day < 1 || month > 12)
		return false;
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			maxDays = 31;
			break;
		case 4: case 6: case 11: case 9:
			maxDays = 30;
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				maxDays = 29;
			else
				maxDays = 28;
			break;
		default:
			return false;
	}
	return (day <= maxDays);
}

bool	BitcoinExchange::checkDates(std::string line)
{
	std::stringstream ss(line);
	int year, month, day;
	char c1, c2;
	if (line[4] != '-' || line[7] != '-' || line.length() != 10)
		return false;
	if (!(ss >> year >> c1 >> month >> c2 >> day))
		return false;
	if (!checkFormat(year, month, day))
		return false;
	return true;
}

void BitcoinExchange::_extractWorth(const std::string file)
{
	std::ifstream infile(file.c_str());
	std::string input;
	std::string date;
	if (!infile.is_open())
		throw std::runtime_error("Error: coudn't open the file");
	std::getline(infile, input);
	while (std::getline(infile, input))
	{
		date = input.substr(0, input.find(','));
		if (!checkDates(date))
			throw std::invalid_argument("Error: invalid dates");
	}
}

BitcoinExchange::~BitcoinExchange() {}
