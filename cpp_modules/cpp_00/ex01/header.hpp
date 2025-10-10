/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:32:32 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/10 10:08:52 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>


class Contact
{
  private:
    std::string  first_name;
    std::string  last_name;
    std::string  nickname;
    std::string  phoneNumber;
    std::string  darkestsecret;
  public:
    void  SetFirstName(std::string f)
    {
      first_name = f;
    }
    void  SetLastName(std::string l)
    {
      last_name = l;
    }
    void  SetPhoneNumber(std::string num)
    {
      phoneNumber = num;
    }
    void  SetNickName(std::string name)
    {
      nickname = name;
    }
    void  SetDarkestSecret(std::string secret)
    {
      darkestsecret = secret;
    }
    std::string GetFirstName()
    {
	    return (first_name);
    }
    std::string getLastName()
    {
		  return (last_name);
    }
    std::string GetNickname()
    {
		  return (nickname);
    }
    std::string GetDarkestSecret()
    {
		  return (darkestsecret);
    }
    std::string GetPhoneNumber()
    {
      return phoneNumber;
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
      if (c.GetDarkestSecret().empty())
        return ;
			contacts[next_index] = c;
      next_index = (next_index + 1) % 8;
      if (total_contacts < 8)
			  total_contacts++;
      std::cout << "it's been added to your contacts\n";
	}
    void  search_contacts()
    {
      std::string s;
      if (!total_contacts)
      {
        std::cout << "PhoneBook is empty" << '\n';
        return ;
      }
      while (1)
      {
        std::cout << "Choose an index: ";
        getline(std::cin, s);
        if (std::cin.eof())
          break;
        if (s.empty())
          continue;
        if (s.size() > 1)
        {
          std::cout << "the index must be single digit between 1 and 8" << std::endl;
          continue;
        }
        if (!isdigit(s[0]))
        {
          std::cout << "the index must be a digit" << std::endl;
          continue;
        }
        int num = s[0] - '0';
        if (num > total_contacts)
        {
          std::cout << "The index is invalid" << std::endl;
          continue;
        }
        else
        {
          std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "\n";
          std::cout << std::setw(10) << num << "|"
                    << std::setw(10) << format_column(contacts[num - 1].GetFirstName()) << "|"
                    << std::setw(10) << format_column(contacts[num - 1].getLastName()) << "|"
                    << std::setw(10) << format_column(contacts[num - 1].GetNickname()) << "\n";
        }
      }      
    }
};


#endif
