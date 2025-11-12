/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:27:35 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/12 08:00:04 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & newType): type(newType) {}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	if (this->type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	else if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
