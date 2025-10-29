/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:51:06 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/26 14:33:05 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon* WeaponType;
		std::string name;
	public:
		HumanB();
		void attack();
		HumanB(std::string n);
		void setWeapon(Weapon& weapon);
		void setName(const std::string newName);
		~HumanB();
};

#endif