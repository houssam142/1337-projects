/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:51:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/11 20:28:47 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {std::cout << "Default constructor called" << '\n';}

Fixed::Fixed(const int fixedPt)
{
	std::cout << "Int constructor called" << '\n';
	fixedPoint = fixedPt << fractionalBits;
}

Fixed::Fixed(const float floatingPt)
{
	std::cout << "Float constructor called" << '\n';
	fixedPoint = (floatingPt * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) : fixedPoint(other.fixedPoint) {std::cout << "Copy constructor called" << '\n';}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &other)
		fixedPoint = other.fixedPoint;
	return *this;
}

int Fixed::toInt(void) const
{
	int IntVal = this->fixedPoint >> fractionalBits;
	return (IntVal);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << '\n';
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (float)(fixedPoint) / (1 << fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return out;
}

Fixed::~Fixed() {std::cout << "Destructor called" << '\n';}
