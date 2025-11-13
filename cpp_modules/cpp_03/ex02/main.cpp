/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:48:25 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/13 01:39:48 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap f("Fraggy");

	f.attack("a hostile enemy");
	f.takeDamage(12);
	f.beRepaired(13);
	f.attack("an enemy");
	return 0;
}
