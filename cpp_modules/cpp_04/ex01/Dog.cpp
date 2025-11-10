/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:20:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 11:34:18 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called\n";
	this->thought = new Brain();
}

Dog::Dog(const Dog& w): Animal(w)
{
	this->thought = new Brain();
}

void Dog::makeSound() const
{
	std::cout << this->getType() << " is barking\n";
}

Dog& Dog::operator=(const Dog& d)
{
	if (this != &d)
	{
		delete this->thought;
		this->thought = new Brain(*d.thought);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete this->thought;
}
