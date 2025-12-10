/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:57:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/10 06:47:07 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _signedGrade;
        const int _execGrade;
    public:
        AForm();
        AForm(std::string newName, int SignedGrade, int execGrade);
        const std::string getName() const;
        AForm(const AForm& copy);
        void execute(Bureaucrat const & executor) const;
        AForm& operator=(const AForm& f);
        virtual void execute() = 0;
        bool getSigned() const;
        int getSignedGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat& b);
        ~AForm();
};

std::ostream& operator<<(std::ostream& out, const AForm& f);
