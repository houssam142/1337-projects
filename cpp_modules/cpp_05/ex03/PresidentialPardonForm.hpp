#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        void executeAction() const;
        PresidentialPardonForm& operator=(const PresidentialPardonForm& eq);
        ~PresidentialPardonForm();
};
