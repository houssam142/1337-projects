/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:25:57 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/24 13:53:11 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>>words = {{2, 3, 9}};

    for (vector<int> word : words)
        cout << word[0] << "\n";
    cout << endl;
}
