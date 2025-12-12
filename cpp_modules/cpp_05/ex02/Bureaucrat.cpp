/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:58:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/12 20:51:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string newName, int grade): name(newName), grade(grade)
{
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150) 
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): grade(copy.grade)
{
  if (this->grade > 150)
    throw Bureaucrat::GradeTooHighException();
  else if (this->grade < 1)
    throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::executeForm(AForm const & form) const
{
  try
  {
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << '\n';
  }
  catch(const std::exception& e)
  {
    std::cerr << this->name << " coudn't execute " << form.getName() << " because " << e.what() << '\n';
  }
}

void Bureaucrat::signForm(AForm& form)
{
  try
  {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << '\n';
  }
  catch (std::exception const& exception)
  {
    std::cout << this->name << " couldn't sign " << form.getName() << " because " << exception.what();
  }
}

void Bureaucrat::incrementGrade()
{
  this->grade--;
  if (grade < 1)
    throw GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
  this->grade++;
  if (grade > 150)
    throw GradeTooHighException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Bureaucrat: Grade too high\n";  
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Bureaucrat: Grade too low\n";
}

const std::string Bureaucrat::getName() const
{
  return this->name;
}

int Bureaucrat::getGrade() const
{
  return this->grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
  if (this != &other)
  {
    this->grade = other.grade;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
  out << other.getName() << ", bureaucrat grade " << other.getGrade();
  return out;
}

Bureaucrat::~Bureaucrat() {}

