#include "Intern.hpp"

Intern::Intern() {}

AForm* Intern::shrubberyCreation(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::presidentialPardon(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::robotomyRequest(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	AForm* (Intern::*p[3])(const std::string) = {&Intern::shrubberyCreation, &Intern::robotomyRequest, &Intern::presidentialPardon};
	const std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == formTypes[i])
			return (this->*p[i])(target);
	}
	std::cerr << "Intern coudn't create form " << name << '\n';
	return NULL;
}

Intern::Intern(const Intern& copy) {(void)copy;}

Intern& Intern::operator=(const Intern& eq)
{
	(void)eq;
	return *this;
}

Intern::~Intern() {}
