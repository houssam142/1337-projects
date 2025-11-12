/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:48:45 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/12 07:53:05 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {}

Cure::Cure(const Cure& o): AMateria(o) {}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}


Cure::~Cure() {std::cout << "Cure destructor called\n";}
