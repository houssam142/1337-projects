#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_extractWorth("data.csv");
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy): _rates(copy._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& eq)
{
	if (this != &eq)
		this->_rates = eq._rates;
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

bool 	checkPrice(std::string price)
{
	char *leftOver = NULL;
	double priceUsd = std::strtod(price.c_str(), &leftOver);
	if (*leftOver || leftOver == price.c_str())
		return false;
	if (priceUsd < 0)
		return false;
	return true;
}

void BitcoinExchange::_extractBitcoins(const std::string arg)
{
	std::ifstream infile(arg.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: file not open");
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr <<  "Error: bad input => " << line << '\n';
			continue;
		}
		std::string rawDate = line.substr(0, pos);
		std::string rawbtc = line.substr(pos + 1);
		size_t start = rawDate.find_first_not_of(" \t");
		size_t end = rawDate.find_last_not_of(" \t");
		if (start == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << '\n';
			continue;
		}
		std::string date = rawDate.substr(start, end - start + 1);

		size_t vS = rawbtc.find_first_not_of(" \t");
		size_t vE = rawbtc.find_last_not_of(" \t");
		std::string valStr = (vS == std::string::npos) ? "" : rawbtc.substr(vS, vE - vS + 1);
		if (!checkDates(date))
		{
			std::cerr << "Error: bad input => " << date << "\n";
			continue;
		}
		char *leftOver = NULL;
		double d = strtod(valStr.c_str(), &leftOver);
		if (*leftOver || leftOver == valStr.c_str())
		{
			std::cerr << "Error: bad input => " << valStr << "\n";
			continue;
		}
		if (d < 0)
		{
			std::cerr << "Error: not a positive number.\n";
			continue;
		}
		if (d > 1000)
		{
			std::cerr << "Error: too large a number.\n";
			continue;
		}
		std::map<std::string, double>::iterator it = this->_rates.lower_bound(date);
		if (it != this->_rates.end() && it->first == date)
			std::cout << date << " => " << d << " = " << d * it->second << '\n';
		else if (it != this->_rates.begin())
		{
			--it;
			std::cout << date << " => " << d << " = " << d * it->second << '\n';
		}
		else
			std::cerr << "Error: data out of range => " << date << '\n';
	}
}

void BitcoinExchange::_extractWorth(const std::string file)
{
	std::ifstream infile(file.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: coudn't open the file");
	std::string input, date, price;
	std::getline(infile, input);
	while (std::getline(infile, input))
	{
		char *end = NULL;
		date = input.substr(0, input.find(','));
		price = input.substr(input.find(',') + 1, input.size());
		double Price = std::strtod(price.c_str(), &end);
		if (*end || end == price.c_str())
			continue;
		this->_rates.insert(std::make_pair(date, Price));
	}
	infile.close();
}

BitcoinExchange::~BitcoinExchange() {}
