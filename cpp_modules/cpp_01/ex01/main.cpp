/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:52:56 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:18:16 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
  int N = 3;
  Zombie* horde = zombieHorde(N, "houssam");
  if (!horde)
    return 1;
  for (int i = 0; i < N ; i++)
    horde[i].announce();
  delete[] horde;
  return 0;
}

