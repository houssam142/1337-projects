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
	for (unsigned int i = 0; i < arg.size(); i++)
	{
		if (std::isdigit(arg[i]))
			s.push(arg[i] - '0');
		if (arg[i] == ' ')
			continue;
		else if (isArithmetic(arg[i]))
				Operations(s, arg[i]);
		else if (!std::isdigit(arg[i]))
			throw std::runtime_error("Error");
	}
	if (s.size() != 1)
		throw std::runtime_error("Error");
	std::cout << s.top() << '\n';
}
