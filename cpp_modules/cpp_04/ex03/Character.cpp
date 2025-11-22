/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:55:42 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/19 03:50:14 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& newName): name(newName)
{
	for (int i = 0; i < invSize; i++)
		this->_slots[i] = 0;
}

Character::Character(const Character& oChar): name(oChar.name)
{
	for (int i = 0; i < invSize; i++)
	{
		this->_slots[i] = oChar._slots[i] ? oChar._slots[i]->clone() : 0;
	}
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < invSize; i++)
	{
		if (this->_slots[i] == 0)
		{
			this->_slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_slots[idx])
			this->_slots[idx] = 0;
	}
}

Character& Character::operator=(const Character& eq)
{
	if (this != &eq)
	{
		for (int i = 0; i < invSize; i++)
		{
			if (this->_slots[i])
			{
				delete this->_slots[i];
				this->_slots[i] = 0;
			}
		}
		for (int i = 0; i < invSize; i++)
		{
			this->_slots[i] = eq._slots[i]? eq._slots[i]->clone() : 0;
		}
	}
	return *this;
}

void Character::use(int index, ICharacter& target)
{
	if (index >= 0 && index < 4)
	{
		if (this->_slots[index])
			this->_slots[index]->use(target);
	}
}

std::string const & Character::getName() const
{
	return this->name;
}

Character::~Character()
{
	for (int i = 0; i < invSize; i++)
	{
		if (this->_slots[i])
			delete this->_slots[i];
	}
}
