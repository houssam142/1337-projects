/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:57:27 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/22 12:01:53 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void  Contact::SetFirstName(std::string f)
{
    first_name = f;
}
void  Contact::SetLastName(std::string l)
{
    last_name = l;
}
void  Contact::SetPhoneNumber(std::string num)
{
    phoneNumber = num;
}
void  Contact::SetNickName(std::string name)
{
    nickname = name;
}
void  Contact::SetDarkestSecret(std::string secret)
{
    darkestsecret = secret;
}
std::string Contact::getFirstName()
{
    return (first_name);
}
std::string Contact::getLastName()
{
    return (last_name);
}
std::string Contact::getNickname()
{
    return (nickname);
}
std::string Contact::getDarkestSecret()
{
    return (darkestsecret);
}
std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

Contact Contact::add_contact()
{
    std::string input;
    Contact c;
    while (1)
    {
        std::cout << "enter your first name: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return c;
        if (input.empty())
		{
            std::cout << "Field is empty" << std::endl;
            continue ;
		}
        c.SetFirstName(input);
        break;
    }
    while (1)
    {
        std::cout << "enter your last name: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return c;
        if (input.empty())
		{
            std::cout << "Field is empty" << std::endl;
            continue;
		}
        c.SetLastName(input);
        break;
    }
    while (1)
    {
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return c;
        if (input.empty())
		{
            std::cout << "Field is empty" << std::endl;
            continue;
		}
        c.SetPhoneNumber(input);
        break;
    }
    while (1)
    {
        std::cout << "Enter your nickname: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return c;
        if (input.empty())
		{
            std::cout << "Field is empty" << std::endl;
            continue;
		}
        c.SetNickName(input);
        break;
    }
    while (true)
    {
        std::cout << "Enter your Darkest secret: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return c;
        if (input.empty())
		{
            std::cout << "Field is empty" << std::endl;
            continue;
		}
        c.SetDarkestSecret(input);
        break;
    }
    return c;
}
