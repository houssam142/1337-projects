/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:49:43 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:28:35 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon& weapon) : name(n), weapon(weapon) {}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << '\n';
}

HumanA::~HumanA() {std::cout << "HumanA destructor called\n";}