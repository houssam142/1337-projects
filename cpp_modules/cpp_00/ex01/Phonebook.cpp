/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:06:46 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/22 14:05:02 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string  format_column(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    return str;
}
void	PhoneBook::store()
{
    Contact c;

    c = c.add_contact();
    if (c.getDarkestSecret().empty())
        return ;
    contacts[next_index] = c;
    next_index = (next_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
    std::cout << "it's been added to your contacts\n";
}
void  PhoneBook::search_contacts()
{
    std::string s;
    if (!total_contacts)
    {
        std::cout << "PhoneBook is empty" << '\n';
        return ;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < total_contacts; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << format_column(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << format_column(contacts[i].getLastName()) << "|"
                  << std::setw(10) << format_column(contacts[i].getNickname()) << "\n";
    }
    std::cout << "Choose an index: ";
    getline(std::cin, s);
    if (std::cin.eof())
    {
        std::cout << '\n';
        return ;
    }
    if (s.size() > 1)
    {
        std::cout << "the index must be single digit between 1 and 8" << '\n';
        return ;
    }
    if (!isdigit(s[0]))
    {
        std::cout << "the index must be a digit" << '\n';
        return ;
    }
    int num = s[0] - '0';
    if (num + 1 > total_contacts)
    {
        std::cout << "The index is invalid" << '\n';
        return ;
    }
    else
    {
        std::cout   << "First Name" << ": " << contacts[num].getFirstName() << '\n'
                    << "Last Name" << ": " << contacts[num].getLastName() << '\n'
                    << "Nickname" << ": " << contacts[num].getNickname() << '\n'
                    << "PhoneNumber" << ": " << contacts[num].getPhoneNumber() << '\n'
                    << "DarkestSecret" << ": " << contacts[num].getDarkestSecret() << '\n';
    }      
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
        else
            std::cout << "Wrong input\n";
    }
    std::cout << '\n';
    return 0;
}
