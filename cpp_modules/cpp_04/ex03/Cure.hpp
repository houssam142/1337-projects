/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:20:50 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/12 07:51:08 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:
		std::string name;
	public:
		Cure();
		Cure(const Cure& o);
		Cure& operator=(const Cure& w);
		AMateria* clone() const;
		~Cure();
};

#endif
