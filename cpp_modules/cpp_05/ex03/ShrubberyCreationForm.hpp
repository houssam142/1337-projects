#pragma once

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& eq);
		ShrubberyCreationForm(std::string const & _target);
		void executeAction() const;
		~ShrubberyCreationForm();

};