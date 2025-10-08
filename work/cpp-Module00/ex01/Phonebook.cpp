/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:37:21 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/07 11:35:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class phonebook
{
	private:
		contact	contacts[8];
		int	next_index;
		int	total_contacts;
	public:
		phonebook() : next_index(0), total_contacts(0) {}
	string  formatColumn(const string &s)
    {
        if (s.length() > 10)
            return s.substr(0, 9) + ".";
        return s;
    }
	void	store()
	{
			contact c = add_contact();			
			contacts[next_index] = c;
			next_index = (next_index + 1) % 8;
			if (total_contacts < 8)
				total_contacts++;
			cout << "Contact added successfuly." << "\n";
	}
	void	search()
	{
		if (!total_contacts)
		{
			cout << "PhoneBook is empty.\n";
			return;
		}
		cout << setw(10) << "Index" << "|"
			 << setw(10) << "First Name" << "|"
			 << setw(10) << "Last Name" << "|"
			 << setw(10) << "Nickname" << "\n";
		for (int i = 0; i < total_contacts; i++)
		{
			string f_name = contacts[i].getFirstName();	
			string l_name = contacts[i].getLastName();
			string nickn = contacts[i].getNickname();
	
			cout << setw(10) << i + 1 << "|"
				 << setw(10) << formatColumn(f_name) << "|"
				 << setw(10) << formatColumn(l_name) << "|"
				 << setw(10) << formatColumn(nickn) << "\n"; 
		}
	}
};

contact	add_contact()
{
	string	input;
	contact	c;
	while (true)
	{
		cout << "enter first name: ";
		getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input.empty())
			continue ;
		c.setFirstName(input);
		break ;
	}
	while (true)
	{
		cout << "enter last name: ";
		getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input.empty())
			continue ;
		c.setLastName(input);
		break ;
	}
	while (true)
	{
		cout << "enter nickname: ";
		getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input.empty())
			continue ;
		c.setNickName(input);
		break ;
	}
	while (true)
	{
		cout << "enter phone number: ";
		getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input.empty())
			continue ;
		c.setPhoneNumber(input);
		break ;
	}
	while (true)
	{
		cout << "enter the darkest secret: ";
		getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input.empty())
			continue;
		c.setDarketSecret(input);
		break ;
	}
	return c;
}
	
int main()
{
	string choice;
	phonebook	book;
	while (1)
	{
		cout << "What is your choice: ";
		getline(std::cin, choice);
		if (std::cin.eof())
			break ;
		if (choice == "EXIT")
			break ;
		if (choice == "ADD")
			book.store();
		if (choice == "SEARCH")
			book.search();
	}
	return 0;
}
