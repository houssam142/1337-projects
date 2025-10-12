/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:32:37 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/12 12:12:05 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	incrementRef(int &w)
{
	w += 10;
}

int main()
{
	int i = 21;
	int *ptr = &i;
	int &wa = i;

	std::cout << "before increment: " << i << std::endl;
	std::cout << "before increment: " << *ptr << std::endl;
	std::cout << "before increment: " <<  wa << std::endl;

	incrementRef(i);

	std::cout << "after increment: " << i << std::endl;
	std::cout << "after increment: " << wa << std::endl;
	std::cout << "after increment: " << *ptr << std::endl;
}
