#include "BitcoinExchange.hpp"

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
			std::cerr << "Error: bad input => " << line << '\n';
			continue;
		}
		char *leftOver = NULL;
		double d = strtod(valStr.c_str(), &leftOver);
		if (*leftOver || leftOver == valStr.c_str())
		{
			std::cerr << "Error: bad input => " << valStr << '\n';
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
