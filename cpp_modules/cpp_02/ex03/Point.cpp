/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:14:41 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/16 18:29:52 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::ostream& operator<<(std::ostream &out, const Point &a)
{
	out << a.getX().toFloat() << std::endl << a.getY().toFloat();
	return out;
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
	
}
