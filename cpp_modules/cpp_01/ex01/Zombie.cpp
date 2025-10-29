/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:40:03 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:18:30 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {std::cout << "Zombie constructor called\n";}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string newName)
{
	this->name = newName;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed" << '\n';
}
