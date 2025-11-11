/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:14:41 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 20:05:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {std::cout << "Point constructor called\n";}

Point::Point(const float floatingPt1, const float floatingPt2): x(floatingPt1), y(floatingPt2) {}

std::ostream& operator<<(std::ostream &out, const Point &a)
{
	out << a.getX().toFloat() << std::endl << a.getY().toFloat();
	return out;
}

Point::Point(Point const &other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Fixed const& Point::getX() const
{
	return x;
}

Fixed const& Point::getY() const
{
	return y;
}

Point::~Point() {std::cout << "Point destructor called\n";}
