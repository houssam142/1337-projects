/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:55:42 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:48:56 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& newName): name(newName)
{
	for (int i = 0; i < invSize; i++)
		this->_slots[i] = 0;
}

Character::Character(const Character& oChar): ICharacter(oChar)
{
	new Character(oChar.name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < invSize; i++)
	{
		if (!this->_slots[i])
			this->_slots[i] = m;
	}
}

void Character::unequip(int idx)
{
	if (idx > 0 && idx < 4)
	{
		if (this->_slots[idx])
			this->_slots[idx] = 0;
	}
}

void Character::use(int index, ICharacter& target)
{
	if (index > 0 && index < 4)
	{
		this->_slots[index]->use(target);
	}
}

std::string const & Character::getName() const
{
	return this->name;
}

Character::~Character() {std::cout << "Character destructor called\n";}
