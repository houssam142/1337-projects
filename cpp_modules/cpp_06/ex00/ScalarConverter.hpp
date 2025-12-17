#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <cmath>


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
