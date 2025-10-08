#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class contact
{
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	public:
		contact	add_contact();
	void	setLastName(const string &input)
	{
		last_name = input;
	}
	string	getFirstName()
	{
		return first_name;
	}
	string	getLastName()
	{
		return last_name;
	}
	string	getNickname()
	{
		return nickname;
	}
	void	setPhoneNumber(const string &input)
	{
		phone_number = input;
	}
	void	setNickName(const string &input)
	{
		nickname = input;
	}
	void	setDarketSecret(const string &input)
	{
		darkest_secret = input;
	}
	void	setFirstName(const string &input)
	{
		first_name = input;
	}
};

contact	add_contact();

#endif
