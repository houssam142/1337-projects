/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:11:13 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/12 13:26:29 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string* ptr = &name;
	std::string& ref = name;
	
	std::cout << &name << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;
	std::cout << name << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}