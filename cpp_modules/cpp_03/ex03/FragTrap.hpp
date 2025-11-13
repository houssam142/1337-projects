#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& o);
		FragTrap& operator=(const FragTrap& o);
		void highFivesGuys(void);
		void attack(const std::string& target);
		~FragTrap();	
};

#endif
