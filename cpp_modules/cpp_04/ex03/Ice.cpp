/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:54:45 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:56:25 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria() {std::cout << "Ice constructor called\n";}

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
	(void)w;
	return *this;
}

Ice::~Ice() {}
