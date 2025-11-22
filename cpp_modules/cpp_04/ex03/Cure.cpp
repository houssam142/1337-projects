/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:48:45 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/19 05:34:28 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure& o): AMateria(o) {}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure& Cure::operator=(const Cure& eq)
{
	if (this != &eq)
		AMateria::operator=(eq);
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

Cure::~Cure() {}
