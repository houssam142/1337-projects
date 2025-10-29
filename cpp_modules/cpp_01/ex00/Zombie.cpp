/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:05:39 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:10:38 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {std::cout << "Zombie constructor called\n";}

Zombie::Zombie(std::string newName)
{
	this->name = newName;
}

void	Zombie::announce()
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {std::cout << "Zombie destructor called\n";}
