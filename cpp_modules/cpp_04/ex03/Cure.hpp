/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:20:50 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:55:44 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "Character.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& o);
		Cure& operator=(const Cure& w);
		AMateria* clone() const;
		void use(ICharacter& target);
		virtual ~Cure();
};

#endif
