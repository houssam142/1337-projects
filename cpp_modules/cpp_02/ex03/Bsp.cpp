/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:57:20 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 18:44:14 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int d1, d2, d3;
	d1 = (b.getX().toInt() - a.getX().toInt()) * (point.getY().toInt() - a.getY().toInt()) - (b.getY().toInt() - a.getY().toInt()) * (point.getX().toInt() - a.getX().toInt());
	d2 = (c.getX().toInt() - b.getX().toInt()) * (point.getY().toInt() - b.getY().toInt()) - (c.getY().toInt() - b.getY().toInt()) * (point.getX().toInt() - b.getX().toInt());
	d3 = (a.getX().toInt() - c.getX().toInt()) * (point.getY().toInt() - c.getY().toInt()) - (a.getY().toInt() - c.getY().toInt()) * (point.getX().toInt() - c.getX().toInt());
	return ((d1 > 0 && d2 > 0 && d3 > 0) || (d2 < 0 && d1 < 0 && d3 < 0)) ? true : false;
}