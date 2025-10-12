/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:26:10 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/12 15:35:20 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n) {}

void HumanB::attack() const
{
	if (WeaponType)
		std::cout << name << " attacks with their " << WeaponType->getType() << std::endl;
	else
		std::cout << name << " has no weapons to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon* weapon)
{
	WeaponType = weapon;	
}

