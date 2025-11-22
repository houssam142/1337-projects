/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:26:28 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 20:14:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {std::cout << "Brain constructor called\n";}

Brain& Brain::operator=(const Brain& o)
{
	if (this != &o)
	{
		for (unsigned int i = 0; i < 100; i++)
			this->ideas[i] = o.ideas[i];
	}
	return *this;
}

Brain::Brain(const Brain& b)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
}

Brain::~Brain() {std::cout << "Brain destructor called\n";}
