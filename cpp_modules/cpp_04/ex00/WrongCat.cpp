/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:13:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 18:57:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& o): WrongAnimal(o) {}

void WrongCat::makeSound() const
{
	std::cout << this->type << " is meowing\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {std::cout << "WrongCat destructor called\n";}
