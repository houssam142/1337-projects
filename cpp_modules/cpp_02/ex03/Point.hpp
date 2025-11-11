/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:36:12 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 20:05:37 by hounejja         ###   ########.fr       */
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
		Point();
		Point(const float floatingPt1, const float floatingPt2);
		Point(Point const &other);
		Fixed const& getX() const;
		Fixed const& getY() const;
		Point &operator=(const Point &other);
		~Point();
};
	
bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream &out, const Point &a);

#endif