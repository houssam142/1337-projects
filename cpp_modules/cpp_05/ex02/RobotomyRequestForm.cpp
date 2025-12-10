#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target): AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): _target(copy._target) {}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* Drilling noises *\n";
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy on " << _target << " was a failure\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& eq)
{
	if (this != &eq)
	{
		this->_target = eq._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}