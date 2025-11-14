/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:15:47 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:45:24 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called\n";
	for (int i = 0; i < _iventorySize; i++)
		this->_materias[i] = 0;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < _iventorySize; i++)
	{
		if (!this->_materias[i])
			this->_materias[i] = m->clone();
	}	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _iventorySize; i++)
	{
		if (this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	return 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called\n";
	for (int i = 0; i < _iventorySize; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}
