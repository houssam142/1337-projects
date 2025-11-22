/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:27:35 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/19 03:13:59 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & newType): type(newType) {}

AMateria::AMateria(const AMateria& copy): type(copy.type) {}

std::string const & AMateria::getType() const
{
	return this->type;
}

AMateria& AMateria::operator=(const AMateria& eq)
{
	if (this != &eq)
	{
		this->type = eq.type;
	}
	return *this;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria::~AMateria() {}
