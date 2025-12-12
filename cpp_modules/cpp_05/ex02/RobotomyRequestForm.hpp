#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& eq);
		void executeAction() const;
		~RobotomyRequestForm();
};