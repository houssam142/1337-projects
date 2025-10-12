/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:52:56 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/12 11:04:14 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
  Zombie* horde = zombieHorde(2, "houssam");
  
  for (int i = 0; i < 2 ; i++)
    horde[i].announce();

  delete[] horde;
  return 0;
}

