
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"

class AMateria
{
	protected:
		std::string const type;	
	public:
		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
