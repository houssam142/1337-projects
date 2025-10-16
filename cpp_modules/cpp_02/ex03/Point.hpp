/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:36:12 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/16 13:57:12 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point() : x(0), y(0) {}
		Point(const float floatingPt1, const float floatingPt2) : x(floatingPt1), y(floatingPt2) {}
		Point(Point const &other) : x(other.x), y(other.y) {}
		Fixed const getX() const
		{
			return x;
		}
		Fixed const getY() const
		{
			return y;
		}
		Point &operator=(const Point &other)
		{
			(void)other;
			return *this;
		}
		bool bsp( Point const a, Point const b, Point const c, Point const point);
};

std::ostream& operator<<(std::ostream &out, const Point &a);

#endif