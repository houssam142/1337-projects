#include "ScalarConverter.hpp"

int	countDigitsAfterDot(std::string str)
{
	size_t i = 0;
	int count = 0;
	size_t pos = str.find('.');
	for (i = pos; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			count++;
	}
	return count;
}

bool	allIsDigitforChar(const std::string s)
{
	unsigned int i = 0;
	for (; i < s.size(); i++)
	{
		if (!std::isdigit(static_cast<char>(s[i])))
			return false;
	}
	return true;
}

bool	isFloat(std::string str)
{
	size_t i = 0;
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff" || str == "-nanf" || str == "+nanf")
	return true;
	if (str.size() < 2 || str[str.size() - 1] != 'f')
	return false;
	if (!isdigit(str[str.size() - 2]))
		return false;
	std::string subStr = str.substr(0, str.size() - 1);
	if (subStr[i] == '+' || subStr[i] == '-')
		++i;
	bool hasDigit = false;
	bool hasDot = false;
	for (; i < subStr.size(); i++)
	{
		char c = static_cast<unsigned char>(subStr[i]);
		if (std::isdigit(c))
			hasDigit = true;
		else if (subStr[i] == '.' && !hasDot && hasDigit)
			hasDot = true;
		else
			return false;
	}
	return hasDigit && hasDot;
}

bool	isDouble(std::string s)
{
	size_t i = 0;
	if (!isdigit(s[s.size() - 1]))
		return false;
	if (s == "nan" || s == "+inf" || s == "-inf" || s == "-nan" || s == "+nan")
        return true;
	if (s.size() < 2)
		return false;
	bool hasDigit = false;
	bool hasDot = false;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (; i < s.size(); i++)
	{
		char c = static_cast<unsigned char>(s[i]);
		if (std::isdigit(c))
			hasDigit = true;
		else if (s[i] == '.' && !hasDot)
			hasDot = true;
		else
			return false;
	}
	return hasDigit && hasDot;
}

void	fromFloattoChar(std::string str)
{
	std::string tmp = str.substr(0, str.size() - 1);
	char *end = NULL;
	double num = strtod(tmp.c_str(), &end);
	if (num > std::numeric_limits<char>::max() || std::isnan(num) || num < std::numeric_limits<char>::min()
			|| end == str.c_str() || *end != '\0')
		std::cout << "impossible\n";
	else
	{
		unsigned char c = static_cast<unsigned char>(num);
		std::cout << ((isprint(c)) ? "\'" + std::string(1, c) + "\'\n" : "Non displayable\n");
	}
}

void	fromDoubletochar(std::string s)
{
	char *end = 0;
	double d = strtod(s.c_str(), &end);
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || std::isnan(d)
			|| end == s.c_str() || *end != '\0')
		std::cout << "impossible\n";
	else
	{
		unsigned char c = static_cast<unsigned char>(d);
		std::cout << ((isprint(c)) ? "\'" + std::string(1, c) + "\'\n" : "Non displayable\n");
	}
}

void	convertToChar(const std::string literal)
{
	std::cout << "char: ";
	if ((literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))))
	{
		unsigned char c = static_cast<unsigned char>(literal[0]);
		std::cout << ((isprint(c)) ? "\'" + std::string(1, c) + "\'\n" : "Non displayable\n");
	}
	else if (allIsDigitforChar(literal))
	{
		char *end = NULL;
		double d = strtod(literal.c_str(), &end);
		if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()
			|| std::isnan(d) || std::isinf(d) || end || end == literal.c_str())
			std::cout << "impossible\n";
		else
		{
			unsigned char c = static_cast<unsigned char>(d);
			std::cout << ((isprint(c)) ? "\'" + std::string(1, c) + "\'\n" : "Non displayable\n");
		}
	}
	else if (isFloat(literal))
		fromFloattoChar(literal);
	else if (isDouble(literal))
		fromDoubletochar(literal);
	else
		std::cout << "impossible\n";
}

void ScalarConverter::convert(const std::string literal)
{
	convertToChar(literal);
	convertToInt(literal);
	converttoFloat(literal);
	convertToDouble(literal);
}
