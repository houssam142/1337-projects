#include "ScalarConverter.hpp"

bool	allIsDigitforInt(const std::string s)
{
	unsigned int i = 0;
	if (s == "inf" || s == "+inf" || s == "-inf")
		return true;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (; i < s.size(); i++)
	{
		if (!isdigit(static_cast<char>(s[i])))
			return false;
	}
	return true;
}

void    fromFloattoInt(std::string s)
{
    char *leftOver = NULL;
    std::string subStr = s.substr(0, s.size() - 1);
    double  d = strtod(subStr.c_str(), &leftOver);
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()
        || *leftOver != '\0' || leftOver == subStr.c_str() || s == "nanf" || s == "-nanf" || s == "+nanf")
        std::cout << "impossible\n";
    else
    {
        int w = static_cast<int>(d);
        std::cout << w << '\n';
    }
}

void    formDoubletoInt(std::string p)
{
    char *leftOver = NULL;
    double d = strtod(p.c_str(), &leftOver);
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()
        || *leftOver || leftOver == p.c_str() || p == "nan" || p == "-nan" || p == "+nan")
        std::cout << "impossible\n";
    else
    {
        int num = static_cast<int>(d);
        std::cout << num << '\n';
    }
}

void    convertToInt(std::string arg)
{
    std::cout << "int: ";
    if ((arg.size() == 1 && !isdigit(static_cast<unsigned char>(arg[0]))))
    {
        int num = static_cast<int>(arg[0]);
        std::cout << num << '\n';
    }
    else if (allIsDigitforInt(arg))
    {
        char *leftOver = NULL;
        double d = strtod(arg.c_str(), &leftOver);
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()
            || *leftOver != '\0' || leftOver == arg.c_str())
                std::cout << "impossible\n";
        else
        {
            int num = static_cast<int>(d);
            std::cout << num << '\n';
        }
    }
    else if (isFloat(arg))
        fromFloattoInt(arg);
    else if (isDouble(arg))
        formDoubletoInt(arg);
    else
        std::cout << "impossible\n";
}
