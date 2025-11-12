/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:55:42 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/11 15:04:22 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

ICharacter::~ICharacter() {}

Character::Character(const std::string& newName): name(newName) {}

Character::Character(const Character& oChar): ICharacter(oChar)
{
	new Character(oChar.name);
}

void Character::equip(AMateria* m)
{
	
}

void Character::unequip(int idx)
{
	
}

void Character::use(int index, ICharacter& target)
{
	
}

std::string const & Character::getName() const
{
	return this->name;
}
