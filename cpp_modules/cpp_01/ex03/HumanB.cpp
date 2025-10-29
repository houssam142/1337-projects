/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:26:10 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:20:13 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {std::cout << "HumanB default constructor called\n";}

HumanB::HumanB(std::string n) : name(n) {}

void HumanB::setName(const std::string newName)
{
	this->name = newName;
}

void HumanB::attack()
{
	if (WeaponType)
		std::cout << name << " attacks with their " << WeaponType->getType() << '\n';
	else
		std::cout << name << " has no weapons to attack with" << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
	WeaponType = &weapon;	
}

HumanB::~HumanB() {std::cout << "HumanB destructor called\n";}

