/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:20:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 18:11:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called\n";
	this->type = "Dog";
}

Dog::Dog(const Dog& w): Animal(w) {}

void Dog::makeSound() const
{
	std::cout << this->type << " is barking\n";
}

Dog& Dog::operator=(const Dog& d)
{
	if (this != &d)
		Animal::operator=(d);
	return *this;
}

Dog::~Dog() {std::cout << "Dog destructor called\n";}
