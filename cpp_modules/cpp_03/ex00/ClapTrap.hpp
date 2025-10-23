#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDmg;
	public:
		ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setName(const std::string& name);
		unsigned int getAttackDmg() const;
		unsigned int gethitPoints() const;
		~ClapTrap();
};

#endif
