#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void easyfind(T& cont, int value)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), value);
	if (it == cont.end())
		throw std::logic_error("There is no occurence of that value");
	else
		std::cout << "Found it\n";
}
