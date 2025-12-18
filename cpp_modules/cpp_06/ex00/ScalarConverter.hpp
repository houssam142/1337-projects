#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <cmath>


class ScalarConverter
{
	private:
		std::string a; // offset 8
		int q; 
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& eq);
		~ScalarConverter();
	public:
		static void convert(const std::string literal);
};


class f: public ScalarConverter
{
	private:
		int a; // offset ?
};

void    convertToInt(std::string arg);
bool	isFloat(std::string str);
bool	isDouble(std::string s);
void    converttoFloat(std::string arg);
bool	allIsDigitforInt(const std::string s);
void	convertToDouble(std::string arg);
