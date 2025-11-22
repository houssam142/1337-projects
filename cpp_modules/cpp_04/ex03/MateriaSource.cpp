/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:15:47 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/19 04:00:32 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < _iventorySize; i++)
		this->_materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < _iventorySize; i++)
	{
		this->_materias[i] = copy._materias[i] ? copy._materias[i]->clone() : 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& eq)
{
	if (this != &eq)
	{
		for (int i = 0; i < _iventorySize; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
		}
		for (int i = 0; i < _iventorySize; i++)
		{
			this->_materias[i] = eq._materias[i] ? eq._materias[i]->clone() : 0;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < _iventorySize; i++)
	{
		if (this->_materias[i] == 0)
		{
			this->_materias[i] = m->clone();
			delete m;
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _iventorySize; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	return 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _iventorySize; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}
