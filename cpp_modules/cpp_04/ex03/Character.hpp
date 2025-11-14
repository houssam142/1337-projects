/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:18:11 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/14 21:38:22 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria* _slots[3];
		static const int invSize = 4;
		AMateria* UMateria;
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
