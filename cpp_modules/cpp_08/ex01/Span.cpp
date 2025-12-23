#include "Span.hpp"

Span::Span(unsigned int N): _maxSize(N)
{
    this->_container.reserve(N);
}

int Span::longestSpan()
{
	if (this->_container.size() < 2)
		throw std::length_error("Need at least 2 numbers");
	int max_num = *std::max_element(this->_container.begin(), this->_container.end());
	int min_num = *std::min_element(this->_container.begin(), this->_container.end());
	return abs(max_num - min_num);
}

int Span::shortestSpan()
{
	if (this->_container.size() < 2)
		throw std::length_error("Need at least 2 numbers");
	int minNum = INT_MAX;
	std::vector<int> sorted = this->_container;
	sort(sorted.begin(), sorted.end());
	for (unsigned int i = 0; i + 1 < sorted.size(); i++)
	{
		int res = abs(sorted[i] - sorted[i + 1]);
		if (res < minNum)
			minNum = res;
	}
	return minNum;
}

void Span::addNumber(int num)
{
	if (this->_maxSize == this->_container.size())
		throw std::out_of_range("out of bounds");
	this->_container.push_back(num);
}

Span::~Span() {}
