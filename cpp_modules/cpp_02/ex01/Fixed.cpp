/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:51:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/15 00:55:48 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	int IntVal = this->fixedPoint >> fractionalBits;
	return (IntVal);
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedPoint) / (1 << fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return out;
}
