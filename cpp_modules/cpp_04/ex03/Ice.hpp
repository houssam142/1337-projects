/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:58:26 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:55:47 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "Character.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& o);
		Ice& operator=(const Ice& w);
		AMateria* clone() const;
		void use(ICharacter& target);
		virtual ~Ice();
};

#endif
