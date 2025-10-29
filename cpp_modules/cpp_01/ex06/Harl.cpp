/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:59:35 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:35:12 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int getLevel(std::string level)
{
	if (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return -1;
}

void Harl::complain(std::string level)
{
	void (Harl::*actions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lvl = getLevel(level);
	switch (lvl)
	{
		case 0:
			for (int i = 0; i < 4; i++)
			{
				std::cout << "[ " << levels[i] << " ]" << std::endl;
				(this->*actions[i])();		
			}
		break;
		case 1:
			for (int i = 1; i < 4; i++)
			{
				std::cout << "[ " << levels[i] << " ]" << std::endl;
				(this->*actions[i])();
			}
		break;
			case 2:
			for (int i = 2; i < 4; i++)
			{
				std::cout << "[ " << levels[i] << " ]" << std::endl;
				(this->*actions[i])();
			}
		break;
		case 3:
			for (int i = 3; i < 4; i++)
			{
				std::cout << "[ " << levels[i] << " ]" << std::endl;
				(this->*actions[i])();
			}
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
