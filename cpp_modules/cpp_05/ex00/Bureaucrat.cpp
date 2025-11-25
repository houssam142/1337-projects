/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 05:56:48 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/25 17:55:40 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string newName, int newGrade): name(newName), grade(newGrade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name), grade(copy.grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		this->grade = b.grade;
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	return *this;
}

void Bureaucrat::gradeIncrement()
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::gradeDecrement()
{
	this->grade++;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low\n";
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

const std::string Bureaucrat::getName() const
{
	return this->name;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;	
}

Bureaucrat::~Bureaucrat() {}
