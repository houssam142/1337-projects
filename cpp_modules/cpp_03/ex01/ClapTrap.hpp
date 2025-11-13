#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDmg;
	public:
		ClapTrap();
		ClapTrap(const std::string& newName);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		ClapTrap(const ClapTrap& o);
		ClapTrap& operator=(const ClapTrap& eq);
		unsigned int getAttackDmg() const;
		unsigned int gethitPoints() const;
		unsigned int getEnergyPoints() const;
		~ClapTrap();
};

#endif
