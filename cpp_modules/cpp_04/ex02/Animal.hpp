/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:16:59 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 18:10:01 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual void makeSound() const = 0;
		Animal(const Animal& a);
		std::string getType() const;
		Animal& operator=(const Animal& a);
		virtual ~Animal();
};

#endif
