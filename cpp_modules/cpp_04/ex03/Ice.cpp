/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:54:45 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/12 07:55:52 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {}

Ice::Ice(const Ice& o): AMateria(o) {}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

Ice& Ice::operator(const Ice& w)
{
	if (this != &w)
	{
		this = new Ice(w);
	}
	return *this;
}

Ice::~Ice() {}
