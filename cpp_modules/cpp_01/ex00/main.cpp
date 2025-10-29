/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:02:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:09:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("HeapZombie:");
	heapZombie->announce();
	
	randomChump("stackZombie:");
	delete heapZombie;
	return 0;
}
