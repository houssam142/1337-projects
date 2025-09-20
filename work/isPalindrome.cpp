/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isPalindrome.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:31:39 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/13 08:29:14 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>

using namespace std;
    

bool    isPalindrome(int x)
{
    int res = 0;
    int num = x;
    int sign = 1;
    if (x < 0)
        return false;
    while (num != 0)
    {
        int rem = num % 10;
        if (res > (INT_MAX - rem) / 10)
            return INT_MAX;
        res = res * 10 + rem;
        num /= 10;
    }
    return res == x;
}

int main()
{
    int x = 1234567899;
    bool flag = isPalindrome(x);
    if (!flag)
        cout << "false" << "\n";
    else
        cout << "true" << "\n";
    return 0;
}