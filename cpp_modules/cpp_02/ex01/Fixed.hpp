/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:51:29 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/15 00:56:29 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
	public:
		Fixed() : fixedPoint(0) {std::cout << "Default constructor called" << std::endl;}
		Fixed(const int fixedPt)
		{
			std::cout << "Int constructor called" << std::endl;
			fixedPoint = fixedPt << fractionalBits;
		}
		Fixed(const float floatingPt)
		{
			std::cout << "Float constructor called" << std::endl;
			fixedPoint = roundf(floatingPt * (1 << fractionalBits));
		}
		Fixed(const Fixed &other) : fixedPoint(other.fixedPoint) {std::cout << "Copy constructor called" << std::endl;}
		Fixed &operator=(const Fixed &other)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other)
			{
				fixedPoint = other.fixedPoint;
			}
			return *this;
		}
		~Fixed() {std::cout << "Destructor called" << std::endl;}
		float toFloat(void) const;
		int toInt(void) const;
};


std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
