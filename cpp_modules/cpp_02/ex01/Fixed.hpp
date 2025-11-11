/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:51:29 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/30 00:20:02 by hounejja         ###   ########.fr       */
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
		Fixed &operator=(const Fixed &other);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
};


std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
