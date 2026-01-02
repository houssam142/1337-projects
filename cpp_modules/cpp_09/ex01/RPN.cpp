#include "RPN.hpp"

bool isArithmetic(char c)
{
	return (c == '-' || c == '+' || c == '*' || c == '/');
}

void	Operations(std::stack<int>& stack, char c)
{
	if (stack.size() < 2)
		throw std::invalid_argument("Error");
	int a, b;

	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();
	if (c == '+')
		stack.push(a + b);
	else if (c == '-')
		stack.push(a - b);
	else if (c == '*')
		stack.push(a * b);
	else if (c == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		stack.push(a / b);
	}
}

void reversePolishNotation(std::string arg)
{
	if (arg.empty())
		throw std::invalid_argument("Error: empty arg");
	std::stack<int> s;
	bool prevWasDigit = false;
	for (unsigned int i = 0; i < arg.size(); i++)
	{
		if (arg[i] == ' ')
		{
			prevWasDigit = false;
			continue;
		}
		if (std::isdigit(arg[i]))
		{
			if (prevWasDigit)
				throw std::runtime_error("Error");
			s.push(arg[i] - '0');
			prevWasDigit = true;
		}
		else if (isArithmetic(arg[i]))
			Operations(s, arg[i]);
		else
			throw std::runtime_error("Error");
	}
	if (s.size() != 1)
		throw std::runtime_error("Error");
	std::cout << s.top() << '\n';
}
