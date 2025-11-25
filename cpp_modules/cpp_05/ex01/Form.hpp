/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:57:23 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/25 21:45:14 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _signedGrade;
        const int _execGrade;
    public:
        Form();
        Form(std::string newName, int SignedGrade, int execGrade);
        const std::string getName() const;
        Form(const Form& copy);
        Form& operator=(const Form& f);
        bool getSigned() const;
        int getSignedGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat& b);
        ~Form();
};

std::ostream& operator<<(std::ostream& out, const Form& f);
