#include "FragTrap.hpp"

FragTrap::FragTrap() {std::cout << "FragTrap constructor called\n";}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDmg = 30;
}

FragTrap::FragTrap(const FragTrap& o): ClapTrap(o) {}

FragTrap& FragTrap::operator=(const FragTrap& o)
{
	if (this != &o)
		this->name = o.name;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDmg << " points of damage!\n"; 
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Positive high-fives request\n";
}

FragTrap::~FragTrap() {std::cout << "FragTrap destructor called\n";}
