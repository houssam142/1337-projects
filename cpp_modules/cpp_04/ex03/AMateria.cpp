/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:27:35 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:55:25 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria::AMateria() {std::cout << "AMateria constructor called\n";}

AMateria::AMateria(std::string const & newType): type(newType) {}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
		std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria::~AMateria() {std::cout << "AMateria destructor called\n";}
