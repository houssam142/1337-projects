/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:20:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 10:57:04 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {std::cout << "Dog constructor called\n";}

Dog::Dog(const Dog& w): Animal(w) {}

void Dog::makeSound() const
{
	std::cout << this->getType() << " is barking\n";
}

Dog& Dog::operator=(const Dog& d)
{
	(void)d;
	return *this;
}

Dog::~Dog() {std::cout << "Dog destructor called\n";}
