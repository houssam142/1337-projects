/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:19:53 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 18:13:27 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called\n";
	this->type = "Cat";
	this->idea = new Brain();
}

Cat::Cat(const Cat& c): Animal(c) 
{
	this->idea = new Brain(*c.idea);
}

void Cat::makeSound() const
{
	std::cout << this->type << " is meowing\n";
}

Cat& Cat::operator=(const Cat& c)
{
	if (this != &c)
	{
		Animal::operator=(c);
		delete this->idea;
		this->idea = new Brain(*c.idea);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete idea;
}
