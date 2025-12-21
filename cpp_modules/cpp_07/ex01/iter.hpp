#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* array, int len, F func)
{
  for (int i = 0; i < len; i++)
    func(array[i]);
}

template <typename T, typename F>
void iter(const T* array, int len, F func)
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}
