#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & _target): AForm("Shrubbery Creation form", 145, 137), _target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& eq)
{
	if (this != &eq)
	{
		AForm::operator=(eq);
		this->_target = eq._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction() const
{
	std::string targetStr = this->_target + "_shrubbery";
	std::ofstream outFile(targetStr.c_str());
	outFile << "    /\\\n"
			<< "   /  \\\n"
			<< "  /    \\\n"
			<< " /______\\\n"
			<< "    ||\n"
			<< "    ||\n";
	outFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}