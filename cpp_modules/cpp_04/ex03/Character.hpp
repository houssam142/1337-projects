/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:18:11 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/11 15:03:57 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class Character: public ICharacter
{
	private:
		std::string name;
		unsigned int slot;
	public:
		Character(const std::string& newName);
		Character(const Character& oCharacter);
		Character& operator=(const Character& oChar);
		void equip(AMateria* m);
		void unequip(int idx);
		std::string const & getName() const;
		void use(int idx, ICharacter& target);
		~Character();
};
#endif