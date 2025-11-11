/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:35:56 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/09 22:35:23 by hounejja         ###   ########.fr       */
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
		Fixed();
		Fixed(const int fixedPt);
		Fixed(const float floatingPt);
		Fixed(const Fixed &other);
		~Fixed();
		int getRawBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;
		bool operator<(const Fixed &a) const;
		bool operator>(const Fixed &b) const;
		bool operator==(const Fixed &c) const;
		bool operator!=(const Fixed &d) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &e) const;
		Fixed	operator*(const Fixed &other);
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator/(const Fixed &other);
		Fixed operator++(int postIncrement);
		Fixed& operator++();
		Fixed operator--(int postDecrement);
		Fixed& operator--();
		static Fixed& max(Fixed &a, Fixed &b);
		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);
};
	
std::ostream &operator<<(std::ostream &out, const Fixed &obj);
	

#endif
