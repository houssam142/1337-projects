/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:51:02 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/23 09:59:33 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called\n";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDmg = 20;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in guard keeper mode\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints)
	{
		std::cout << this->name << " attacks " << target << " causing " << this->attackDmg << " points of damage!\n";
		this->energyPoints--;
	}
	else
		std::cout << this->name << " has no energy points left to attack " << target << '\n';
}

ScavTrap::~ScavTrap() {std::cout << "ScavTrap destructor called\n";}