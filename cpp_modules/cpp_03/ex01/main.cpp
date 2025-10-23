/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:48:25 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/23 10:14:20 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav;
	ClapTrap clap;

	clap.setName("Clappy");
	clap.attack("an enemy");
	clap.takeDamage(5);
	clap.beRepaired(1);
	scav.setName("Scavvy");
	scav.attack("a hostile enemy");
	scav.takeDamage(35);
	scav.beRepaired(10);
	return 0;
}
