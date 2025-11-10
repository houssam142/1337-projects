#include "Animal.hpp"

Animal::Animal() {std::cout << "Animal default constructor called\n";}

Animal::Animal(const Animal& a): type(a.type) {}

std::string Animal::getType() const
{
	return this->type;
}

Animal& Animal::operator=(const Animal& a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << this->type << " is making a sound\n";
}

Animal::~Animal() {std::cout << "Animal destructor called\n";}
