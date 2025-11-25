/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 06:02:04 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/25 17:58:18 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Bureaucrat", 1);
	try
	{
		for (int i = b.getGrade(); i < 100; i++)
			b.gradeDecrement();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << b << '\n';
	return 0;
}
