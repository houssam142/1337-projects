#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
	private:
	std::vector<int> _container;
	unsigned int _maxSize;
	public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& eq);
	~Span();
	int longestSpan();
	int shortestSpan();
	void addNumber(int value);
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	while (begin != end && this->_container.size() < this->_maxSize)
		this->_container.push_back(*begin++);
}
