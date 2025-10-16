/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:51:54 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/14 23:51:55 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
	public:
		Fixed() : fixedPoint(0) {std::cout << "Default constructor called" << std::endl;}
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
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
