/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:30:58 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/23 10:08:48 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): hitPoints(10), energyPoints(10), attackDmg(0) {std::cout << "ClapTrap constructor called\n";}

void ClapTrap::setName(const std::string& name)
{
	this->name = name;
}

unsigned int ClapTrap::getAttackDmg() const
{
	return this->attackDmg;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints)
	{
		std::cout << this->name << " attacks " << target << " causing " << this->attackDmg << " points of damage!\n";
		this->energyPoints--;
	}
	else
		std::cout << this->name << " has no energy points left to attack " << target << '\n';
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints - amount > 0)
		this->hitPoints -= amount;
}

unsigned int ClapTrap::gethitPoints() const
{
	return this->hitPoints;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints)
	{
		if (this->hitPoints + amount < 10)
		{
			this->hitPoints += amount;
			this->energyPoints -= 1;
		}
		else if (this->hitPoints + amount > 10)
		{
			this->hitPoints = 10;
			this->energyPoints -= 1;
		}
		std::cout << this->name << " has " << this->hitPoints << " left\n";
	}
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap destructor called\n";}
