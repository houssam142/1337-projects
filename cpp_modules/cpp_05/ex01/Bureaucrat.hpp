/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:59:20 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/25 21:22:33 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
  private:
    const std::string name;
    int grade;
    public:
    Bureaucrat();
    Bureaucrat(const std::string newName, int grade);
    Bureaucrat(const Bureaucrat& copy);
    int getGrade() const;
    const std::string getName() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form);
    Bureaucrat& operator=(const Bureaucrat& o);
    ~Bureaucrat();
    class GradeTooHighException: public std::exception
    {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
      public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

