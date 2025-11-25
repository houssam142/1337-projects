/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:59:06 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/25 21:21:45 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _signedGrade(150), _execGrade(150) {}

Form::Form(std::string newName, int SignedGrade, int execGrade): _name(newName), _signedGrade(SignedGrade), _execGrade(execGrade)
{
    if (_signedGrade < 1 || _execGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_signedGrade > 150 || _execGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string Form::getName() const
{
    return this->_name;
}

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed), _signedGrade(copy._signedGrade), _execGrade(copy._execGrade)
{
    if (this->_signedGrade < 1 || this->_execGrade)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_signedGrade > 150 || this->_execGrade < 150)
        throw Bureaucrat::GradeTooLowException();
}

Form& Form::operator=(const Form& f)
{
    if (this != &f)
        this->_signed = f._signed;
    return *this;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= this->_signedGrade)
        this->_signed = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

int Form::getSignedGrade() const
{
    return this->_signedGrade;
}

int Form::getExecGrade() const
{
    return this->_execGrade;
}

bool Form::getSigned() const
{
    return this->_signed;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Form's name: " << f.getName() << ", has signed grade " << f.getSignedGrade() << " and exec grade " << f.getExecGrade();
    return out;
}

Form::~Form() {}