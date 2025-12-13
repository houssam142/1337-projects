#pragma once

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		AForm* makeForm(const std::string name, const std::string target);
		Intern(const Intern& copy);
		AForm* shrubberyCreation(const std::string target);
		AForm* presidentialPardon(const std::string target);
		AForm* robotomyRequest(const std::string target);
		Intern& operator=(const Intern& eq);
		~Intern();
};