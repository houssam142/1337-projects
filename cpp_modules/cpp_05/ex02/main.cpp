/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:29:21 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/13 08:14:10 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat low("Low Grade", 150);
        Bureaucrat mid("Mid grade", 75);
        Bureaucrat high("High grade", 1);
        ShrubberyCreationForm garden("garden");
        RobotomyRequestForm bender("Bender");
        PresidentialPardonForm zaphod("Zaphod");

        std::cout << low << '\n';
        std::cout << mid << '\n';
        std::cout << high << '\n';

        std::cout << garden << '\n';
        std::cout << bender << '\n';
        std::cout << zaphod << '\n';

        low.signForm(garden);
        low.signForm(bender);
        low.signForm(zaphod);

        mid.signForm(garden);
        mid.signForm(bender);
        mid.signForm(zaphod);

        high.signForm(garden);
        high.signForm(bender);
        high.signForm(zaphod);

        high.executeForm(garden);
        mid.executeForm(bender);
        low.executeForm(zaphod);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what();
    }
    return 0;
}
