/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:19:53 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 20:13:58 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called\n";
	this->type = "Cat";
}

Cat::Cat(const Cat& c): Animal(c) {}

void Cat::makeSound() const
{
	std::cout << this->type << " is meowing\n";
}

Cat& Cat::operator=(const Cat& c)
{
	if (this != &c)
		Animal::operator=(c);
	return *this;
}

Cat::~Cat() {std::cout << "Cat destructor called\n";}
