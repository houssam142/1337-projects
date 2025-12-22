#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& eq);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		bool operator!=(const Array& uneq);
		~Array();
};


template <typename T>
Array<T>::Array(): _array(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	if (n == 0)
		throw std::length_error("size zero");
	this->_array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& copy): _size(copy._size)
{
	this->_array = new T[this->_size]();
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& eq)
{
	if (this != &eq)
	{
		delete[] _array;
		this->_size = eq._size;
		this->_array = new T[eq._size]();
		for (int i = 0; i < this->_size; i++)
			this->_array[i] = eq._array[i];
	}
	return *this;
}

template <typename T>
bool Array<T>::operator!=(const Array& uneq)
{
	return this->_array == uneq._array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::length_error("Index out of bounds");
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw std::length_error("index out of bounds");
	return this->_array[index];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}