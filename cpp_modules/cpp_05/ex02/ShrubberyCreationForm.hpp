#pragma once

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string const _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & _target);
		void executeAction() const;
		~ShrubberyCreationForm();

};