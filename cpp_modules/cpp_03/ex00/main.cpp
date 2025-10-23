/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:29:41 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/23 09:47:28 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap;

	clap.setName("Houssam");
	clap.attack("an enemy");
	clap.attack("an enemy");
	clap.attack("an enemy");
	clap.attack("an enemy");
	clap.takeDamage(5);
	clap.beRepaired(2);
	return 0;
}
