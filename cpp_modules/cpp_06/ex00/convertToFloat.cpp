#include "ScalarConverter.hpp"

void    fromInttoFloat(std::string s)
{
    char *end = NULL;
    double d = strtod(s.c_str(), &end);
    if (*end || end == s.c_str())
        std::cout << "impossible\n";
    else
    {
        float fp = static_cast<float>(d);
        std::cout << std::fixed << std::setprecision(1) << fp << "f\n";
    }
}

void    fromDoubletoFloat(std::string s)
{
    char *end = NULL;
    double d = strtod(s.c_str(), &end);
    int count = countDigitsAfterDot(s);
    if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()
        || *end != '\0' || end == s.c_str())
        std::cout << (s[0] == '+' ? s.substr(1, s.size()) + "f\n" : s + "f\n");
    else
        std::cout << std::fixed << std::setprecision(count) << d << "f\n";
}

void    converttoFloat(std::string arg)
{
    std::cout << "float: ";
    if (arg.size() == 1 && !isdigit(static_cast<unsigned char>(arg[0])))
    {
        float fp = static_cast<float>(arg[0]);
        std::cout << fp;
        if (fp - static_cast<int>(fp) == 0)
            std::cout << ".0";
        std::cout << "f\n";
    }
    else if (allIsDigitforInt(arg))
        fromInttoFloat(arg);
    else if (isFloat(arg))
    {
        char *end = NULL;
        std::string substr = arg.substr(0, arg.size() - 1);
        double d = strtod(substr.c_str(), &end);
        int count = countDigitsAfterDot(arg);
        if (*end || end == substr.c_str())
        {
            std::cout << "impossible\n";
            return ;
        }
        if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()
            || *end || end == arg.c_str())
            std::cout << (arg[0] == '+' ? arg.substr(1, arg.size()) + "\n": arg + '\n');
        else
            std::cout << std::fixed << std::setprecision(count) << d << "f\n";
    }
    else if (isDouble(arg))
        fromDoubletoFloat(arg);
    else
        std::cout << "impossible\n";
}
