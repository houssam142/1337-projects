/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:38:25 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/03 13:40:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    if (ac < 2)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
        return 1;
    }
    for (int i = 1; av[i]; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                av[i][j] -= 32;
            cout << av[i][j];
        }
    }
    cout << "\n";
    return 0;
}