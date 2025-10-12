/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:02:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/11 18:46:43 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("HeapZombie:");
	heapZombie->announce();
	
	delete heapZombie;
	randomChump("stackZombie:");
	return 0;
}
