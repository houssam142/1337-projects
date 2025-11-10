/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:19:58 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/08 13:46:11 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int size = 10;
	const Animal* a[size];
	for (int i = 0; i < size / 2; i++)
		a[i] = new Cat();
	for (int i = size / 2; i < size; i++)
		a[i] = new Dog();
	for (int i = 0; i < size; i++)
		a[i]->makeSound();
	for (int i = 0; i < size; i++)
		std::cout << a[i] << '\n';
	for (int i = 0; i < size; i++)
		delete a[i];
	return 0;
}
