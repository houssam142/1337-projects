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
	return (day >= 1 && day <= maxDays);
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

bool	allIsDigitforInt(const std::string s)
{
	unsigned int i = 0;
	for (; i < s.size(); i++)
	{
		if (!std::isdigit(static_cast<char>(s[i])))
			return false;
	}
	return true;
}


bool 	checkPrice(std::string price)
{
	std::stringstream _price(price);
	int priceUsd;
	if (!allIsDigitforInt(price))
		return false;
	if (!(_price >> priceUsd))
		return false;
	return true;
}

void BitcoinExchange::_extractWorth(const std::string file)
{
	char *end = NULL;
	std::ifstream infile(file.c_str());
	std::string input, date, price;
	if (!infile.is_open())
		throw std::runtime_error("Error: coudn't open the file");
	std::getline(infile, input);
	while (std::getline(infile, input))
	{
		date = input.substr(0, input.find(','));
		price = input.substr(input.find(',') + 1, input.size());
		if (!checkDates(date))
			continue;
		if (!checkPrice(price))
			continue;
		double Price = std::strtod(price.c_str(), &end);
		if (*end || end == price.c_str())
			;
	}
}

BitcoinExchange::~BitcoinExchange() {}
