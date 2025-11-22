/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:19:58 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/21 18:28:49 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Cat* w = new Cat();
	const Dog* q = new Dog();

	w->makeSound();
	q->makeSound();
	delete w;
	delete q;
	return 0;
}
