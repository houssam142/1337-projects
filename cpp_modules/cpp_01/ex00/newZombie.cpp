/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:06:44 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/11 18:28:09 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}

Zombie::~Zombie()
{
	std::cout << this->name << " Destroyed" << std::endl;
}
