/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:55:42 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/12 08:13:20 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

ICharacter::~ICharacter() {}

Character::Character(const std::string& newName): name(newName), slot(0) {}

Character::Character(const Character& oChar): ICharacter(oChar)
{
	new Character(oChar.name);
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		this->slots[slot] = *m;
		slot++;
	}
}

void Character::unequip(int idx)
{
	
}

void Character::use(int index, ICharacter& target)
{
	if (index < 4)
		this->slots[index].use(target);
}

std::string const & Character::getName() const
{
	return this->name;
}
