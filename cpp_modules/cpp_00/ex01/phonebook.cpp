/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:47:36 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/09 22:03:05 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Contact add_contact()
{
    Contact c;
    std::string s;
    while (1)
    {
        std::cout << "enter your first name: ";
        s = c.GetFirstName();
        getline(std::cin, s);
        if (std::cin.eof())
            break;
        if (c.GetFirstName().empty())
            break;
    }
    while (1)
    {
        std::cout << "enter your last name: ";
        s = c.getLastName();
        getline(std::cin, s);
        if (std::cin.eof())
            break;
        if (c.GetFirstName().empty())
            break;
    }
    while (1)
    {
        std::cout << "Enter your phone number: ";
        s = c.GetPhoneNumber();
        getline(std::cin, s);
        if (std::cin.eof())
            break;
        if (s.empty())
            break;
        for (int i = 0; i < s.size(); i++)
        {
            if (!isdigit(s[i]))
            {
                std::cout << "Invalid phone number" << std::endl;
                exit(1);
            }
        }
    }
    while (1)
    {
        std::cout << "Enter your nickname: ";
        s = c.GetNickname();
        getline(std::cin, s);
        if (std::cin.eof())
            break;
        if (c.GetNickname().empty())
            break;
    }
    while (true)
    {
        std::cout << "Enter your Darkest secret: ";
        s = c.GetDarkestSecret();
        getline(std::cin, s);
        if (std::cin.eof())
            break;
        if (c.GetDarkestSecret().empty())
            break;
    }
    return c;
}

int main()
{
    PhoneBook book;
    std::string input;
    while (1)
    {
        std::cout << "Enter an option: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            break;
        if (input == "ADD")
            book.store();
        else if (input == "SEARCH")
            book.search_contacts();
        else if (input == "EXIT")
            break;
    }
    std::cout << std::endl;
    return 0;
}
