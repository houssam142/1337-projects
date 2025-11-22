/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 04:01:03 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/19 04:04:18 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;	
	public:
		AMateria();
		AMateria(std::string const & type);
		std::string const & getType() const;
		AMateria& operator=(const AMateria& eq);
		AMateria(const AMateria& copy);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};

#endif