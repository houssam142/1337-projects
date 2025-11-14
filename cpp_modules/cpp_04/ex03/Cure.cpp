/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:48:45 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:55:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {std::cout << "Cure constructor called\n";}

Cure::Cure(const Cure& o): AMateria(o) {}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

Cure::~Cure() {std::cout << "Cure destructor called\n";}
