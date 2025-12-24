#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <stdexcept>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, int> _rates;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& eq);
		void _extractWorth(const std::string file);
		bool checkDates(std::string line);
		~BitcoinExchange();
};
