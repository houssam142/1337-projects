 	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:25:07 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/10 20:04:35 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _materias[4];
		static const int _iventorySize = 4;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& eq);
		void learnMateria(AMateria* Material);
		AMateria* createMateria(std::string const & type);
		virtual ~MateriaSource();
};

#endif