/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:59:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 20:57:19 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Take just one paramter" << std::endl;
		return 1;
	}
	std::string level = static_cast<std::string>(av[1]);
	Harl harl;
	harl.complain(level);
	return 0;
}
