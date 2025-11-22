/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:54:45 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/19 03:12:16 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice& o): AMateria(o) {}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice& Ice::operator=(const Ice& w)
{
	if (this != &w)
	{
		AMateria::operator=(w);
	}
	return *this;
}

Ice::~Ice() {}
