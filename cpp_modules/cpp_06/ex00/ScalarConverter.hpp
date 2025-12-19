#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& eq);
		~ScalarConverter();
	public:
		static void convert(const std::string literal);
};


void    convertToInt(std::string arg);
int	countDigitsAfterDot(std::string str);
bool	isFloat(std::string str);
bool	isDouble(std::string s);
void    converttoFloat(std::string arg);
bool	allIsDigitforInt(const std::string s);
void	convertToDouble(std::string arg);
