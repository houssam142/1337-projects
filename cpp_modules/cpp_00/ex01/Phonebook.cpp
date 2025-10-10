/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:06:46 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/10 10:04:38 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Contact add_contact()
{
    std::string input;
    Contact c;
    while (1)
    {
        std::cout << "enter your first name: ";
        getline(std::cin, input);
        if (std::cin.eof())
            return c;
        if (input.empty())
            continue ;
        c.SetFirstName(input);
        break;
    }
    while (1)
    {
        std::cout << "enter your last name: ";
        getline(std::cin, input);
        if (std::cin.eof())
            return c;
        if (input.empty())
            continue;
        c.SetLastName(input);
        break;
    }
    while (1)
    {
        std::cout << "Enter your phone number: ";
        getline(std::cin, input);
        if (std::cin.eof())
            return c;
        for (int i = 0; i < static_cast<int>(input.size()); i++)
        {
            if (!isdigit(input[i]))
            {
                std::cout << "Invalid phone number" << std::endl;
                exit(1);
            }
        }
        if (input.empty())
            continue;
        c.SetPhoneNumber(input);
        break;
    }
    while (1)
    {
        std::cout << "Enter your nickname: ";
        getline(std::cin, input);
        if (std::cin.eof())
            break;
        if (input.empty())
            continue;
        c.SetNickName(input);
        break;
    }
    while (true)
    {
        std::cout << "Enter your Darkest secret: ";
        getline(std::cin, input);
        if (std::cin.eof())
            break;
        if (input.empty())
            continue;
        c.SetDarkestSecret(input);
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
