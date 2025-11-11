/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:42:50 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/11 20:28:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0) {std::cout << "Fixed constructor called\n";}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this->fixedPoint;
}

Fixed::Fixed(const Fixed& o): fixedPoint(o.fixedPoint) {}

Fixed& Fixed::operator=(const Fixed& o)
{
	if (this != &o)
		this->fixedPoint = o.fixedPoint;
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

Fixed::~Fixed() {std::cout << "Fixed destructor called\n";}
