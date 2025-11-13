#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {std::cout << "DiamondTrap constructor called\n";}

DiamondTrap::DiamondTrap(const std::string& newName): ClapTrap(newName), FragTrap(newName), ScavTrap(newName), name(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& o): ClapTrap(o), FragTrap(o), ScavTrap(o) {}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& eq)
{
	if (this != &eq)
		this->name = eq.name;
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << this->name << " and ClapTrap's name is " << ClapTrap::name << '\n';
}

DiamondTrap::~DiamondTrap() {std::cout << "DiamondTrap destructor called\n";}
