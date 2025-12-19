#include "ScalarConverter.hpp"

void	fromFloattoDouble(std::string s)
{
	std::string sub = s.substr(0, s.size() - 1);
	char *leftOver = NULL;
	double d = strtod(sub.c_str(), &leftOver);
	if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::min()
		|| *leftOver != '\0' || leftOver == sub.c_str() || std::isnan(d))
		std::cout << (sub[0] == '+' ? sub.substr(1, sub.size()) + "\n" : sub + "\n");

	else
		std::cout << d << '\n';
}

void	fromInttoDouble(std::string s)
{
	char *end = NULL;
	double d = strtod(s.c_str(), &end);
	if (*end != '\0' || end == s.c_str() || std::isnan(d) || std::isinf(d))
		std::cout << (s[0] == '+' ? s.substr(1, s.size()) + "\n" : s + "\n");
	else
	{
		std::cout << d << "\n";
	}
}

void	convertToDouble(std::string arg)
{
	std::cout << "Double: ";
	if (arg.size() == 1 && !std::isdigit(static_cast<unsigned char>(arg[0])))
	{
		double a = static_cast<double>(arg[0]);
		std::cout << a;
		if (a - static_cast<int>(a) == 0)
			std::cout << ".0\n";
	}
	else if (allIsDigitforInt(arg))
		fromInttoDouble(arg);
	else if (isFloat(arg))
		fromFloattoDouble(arg);
	else if (isDouble(arg))
	{
		char *end = NULL;
		double w = strtod(arg.c_str(), &end);
		if (w > std::numeric_limits<double>::max() || w < std::numeric_limits<double>::min()
			|| *end || end == arg.c_str() || std::isnan(w) || std::isinf(w))
            std::cout << (arg[0] == '+' ? arg.substr(1, arg.size()) + "\n" : arg + "\n");
		else
			std::cout << std::fixed << std::setprecision(1) << w << '\n';
	}
	else
		std::cout << "impossible\n";
}
