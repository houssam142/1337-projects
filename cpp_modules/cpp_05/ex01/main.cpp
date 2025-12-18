/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:23:38 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/16 14:00:07 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
  try
  {
    Bureaucrat low("Low", 150);
    Bureaucrat mid("Mid", 75);
    Bureaucrat high("High", 1);
      
    Form easy("EasyForm", 151, 150);
    Form medium("MediumForm", 75, 50);
    Form hard("HardForm", 10, 5);
    
    std::cout << easy << std::endl;
    std::cout << medium << std::endl;
    std::cout << hard << std::endl;
    low.signForm(easy);
    low.signForm(medium);
    low.signForm(hard);  

    mid.signForm(easy);
    mid.signForm(medium);
    mid.signForm(hard);

    high.signForm(easy);
    high.signForm(medium);
    high.signForm(hard);

    std::cout << easy << std::endl;
    std::cout << medium << std::endl;
    std::cout << hard << std::endl;
  }
  catch (std::exception & e)
  {
    std::cerr << e.what();
  }
  return 0;
}
