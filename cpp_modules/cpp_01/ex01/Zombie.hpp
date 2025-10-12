/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:53:07 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/12 10:57:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
	void	announce(void);
	void	setName(std::string n)
	{
		name = n;
	}
};

Zombie* zombieHorde(int N, std::string name);

#endif