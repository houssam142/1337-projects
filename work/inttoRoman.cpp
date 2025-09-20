/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttoRoman.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:51:55 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/13 11:36:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string intToRoman(int num)
{
    map<string, int> mp = {{"M", 1000}, {"I", 1}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}};
    int x = num;
    int size = 0;
    string s;
    while (num > 0)
    {
        num-= mp["M"];
        s.push_back(mp.at(1000));
    }
    return s;
}

int main()
{
    int num = 3749;
    string s = intToRoman(num);
    cout << s << "\n";
    return 0;
}