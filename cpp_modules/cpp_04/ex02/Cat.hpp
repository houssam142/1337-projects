/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:19:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/19 05:43:09 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* idea;
	public:
		Cat();
		Cat(const Cat& c);
		void makeSound() const;
		Cat& operator=(const Cat& w);
		~Cat();
};

#endif
