/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:19:53 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 10:53:21 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {std::cout << "Cat constructor called\n";}

Cat::Cat(const Cat& c): Animal(c) {}

void Cat::makeSound() const
{
	std::cout << this->getType() << " is meowing\n";
}

Cat& Cat::operator=(const Cat& c)
{
	(void)c;
	return *this;
}

Cat::~Cat() {std::cout << "Cat destructor called\n";}
