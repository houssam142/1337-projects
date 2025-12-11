#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & _target): AForm("Shrubbery Creation form", 145, 137), _target(_target) {}

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