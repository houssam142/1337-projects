/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:13:49 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:19:51 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {std::cout << "Weapon constructor called\n";}

Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(std::string tp)
{
	type = tp;
}

Weapon::~Weapon() {std::cout << "Weapon destructor called\n";}
