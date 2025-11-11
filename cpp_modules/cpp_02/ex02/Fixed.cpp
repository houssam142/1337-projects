/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:36:12 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/09 22:38:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const int fixedPt)
{
	fixedPoint = fixedPt << fractionalBits;
}

Fixed::Fixed(const float floatingPt)
{
	fixedPoint = roundf(floatingPt * (1 << fractionalBits));
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.fixedPoint < b.fixedPoint) ? a : b;	
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;	
}

bool Fixed::operator<(const Fixed &a) const
{
	return this->fixedPoint < a.getRawBits();
}

bool Fixed::operator>(const Fixed &b) const
{
	return this->fixedPoint > b.getRawBits();
}

bool Fixed::operator==(const Fixed &c) const
{
	return this->fixedPoint == c.getRawBits();
}

bool Fixed::operator!=(const Fixed &d) const
{
	return this->fixedPoint != d.getRawBits();
}

bool Fixed::operator>=(const Fixed &d) const
{
	return this->fixedPoint >= d.getRawBits();
}

bool Fixed::operator<=(const Fixed &e) const
{
	return this->fixedPoint <= e.getRawBits();
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed res;
	res.fixedPoint = (this->fixedPoint * other.getRawBits()) >> fractionalBits;
	return res;
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed res;
	res.fixedPoint = (this->fixedPoint + other.getRawBits()) >> fractionalBits;
	return res;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed res;
	res.fixedPoint = (this->fixedPoint - other.getRawBits()) >> fractionalBits;
	return res;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed res;
	res.fixedPoint = (this->fixedPoint << fractionalBits) / other.getRawBits();
	return res;
}

Fixed Fixed::operator++(int postIncrement)
{
	(void)postIncrement;
	Fixed temp = *this;
	this->fixedPoint += 1;
	return temp;
}

Fixed& Fixed::operator++()
{
	fixedPoint += 1;
	return *this;
}

Fixed Fixed::operator--(int postDecrement)
{
	(void)postDecrement;
	Fixed res = *this;
	this->fixedPoint -= 1;
	return res;
}

Fixed& Fixed::operator--()
{
	this->fixedPoint -= 1;
	return *this;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

float Fixed::toFloat() const
{
	return (float)(fixedPoint) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
	return this->fixedPoint >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &a)
{
	out << a.toFloat();
	return out;
}

int Fixed::getRawBits(void) const
{
	return this->fixedPoint;
}
