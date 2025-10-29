/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:02:02 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/22 12:02:04 by hounejja         ###   ########.fr       */
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
  void  SetFirstName(std::string f);
  void  SetLastName(std::string l);
  void  SetPhoneNumber(std::string num);
  void  SetNickName(std::string name);
  void  SetDarkestSecret(std::string secret);
  std::string getFirstName();
  std::string getLastName();
  std::string getNickname();
  std::string getDarkestSecret();
  std::string getPhoneNumber();
  Contact  add_contact();
};


class PhoneBook
{
  private:
  Contact contacts[8];
  int     total_contacts;
  int     next_index;
  public:
  PhoneBook() : total_contacts(0), next_index(0) {}
  void  search_contacts();
  void	store();
};


#endif
