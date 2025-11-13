#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& newName);
		DiamondTrap(const DiamondTrap& o);
		DiamondTrap& operator=(const DiamondTrap& eq);
		void attack(const std::string& target);
		void whoAmI();
		~DiamondTrap();
};

#endif
