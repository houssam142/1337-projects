/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 06:02:04 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/16 13:58:22 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Bureaucrat", 0);
		for (int i = b.getGrade(); i < 100; i++)
			b.gradeDecrement();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	return 0;
}
