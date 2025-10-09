/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:32:32 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/08 17:32:33 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>


class Contact
{
  public:
    std::string  first_name;
    std::string  last_name;
    std::string  nickname;
    std::string  phoneNumber;
    std::string  darkestsecret;
  public:
    std::string return_first_name()
    {
	    return (first_name);
    }
    std::string return_last_name()
    {
		  return (last_name);
    }
    std::string return_nickname()
    {
		  return (nickname);
    }
    std::string return_darkestSecret()
    {
		  return (darkestsecret);
    }
};

Contact  add_contact();
class PhoneBook
{
  private:
    Contact contacts[8];
    int     total_contacts;
    int     next_index;
  public:
    PhoneBook() : total_contacts(0), next_index(0) {}
  std::string  format_column(std::string str)
  {
    if (str.length() > 10)
      str = str.substr(0, 9) + ".";
    return str;
  }
	void	store()
	{
			Contact c = add_contact();
			contacts[next_index] = c;
      next_index = (next_index + 1) % 8;
      if (total_contacts < 8)
			  total_contacts++;
      std::cout << "it's been added to your contacts\n";
	}
    void  search_contact()
    {
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
        std::string first_name = contacts[i].return_first_name();
        std::string last_name = contacts[i].return_last_name();
        std::string nickname = contacts[i].return_nickname();
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << format_column(first_name) << "|"
                  << std::setw(10) << format_column(last_name) << "|"
                  << std::setw(10) << format_column(nickname) << "\n";
      }
    }
};


#endif
