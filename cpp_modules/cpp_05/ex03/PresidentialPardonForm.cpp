#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target): AForm("Presidential Pardon Form", 25, 5), _target(target) {}

void PresidentialPardonForm::	executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy), _target(copy._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& eq)
{
	if (this != &eq)
	{
		AForm::operator=(eq);
		this->_target = eq._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
