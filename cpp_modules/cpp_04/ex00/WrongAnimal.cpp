/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:09:06 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 18:57:32 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {this->type = ""; std::cout << "WrongAnimal constructor called\n";}

void WrongAnimal::makeSound() const
{
	std::cout << this->type << " is making the wrong sound\n";
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal destructor called\n";}

