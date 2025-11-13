/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:48:43 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/13 01:36:12 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& newName);
		ScavTrap(const ScavTrap& o);
		ScavTrap& operator=(const ScavTrap& o);
		void attack(const std::string& target);
		void guardGate();
		~ScavTrap();
};

#endif
