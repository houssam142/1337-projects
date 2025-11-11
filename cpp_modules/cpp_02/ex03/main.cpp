/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:35:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 20:06:53 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(3, 3);
	Point edge(5, 0);
	Point outside(10, 10);
	bool flag = bsp(a, b, c, inside);
	std::cout << ((flag == 0) ? "False\n" : "True\n");
	flag = bsp(a, b, c, edge);
	std::cout << ((flag == 0) ? "False\n" : "True\n");
	return 0;
}
