/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tribonacci.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:24:22 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/20 11:36:32 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

void    tribonacci(vector<int> &arr, int length)
{
    int size = arr.size();
    if (size == length)
        return ;
    else if (size > length)
    {
        arr.pop_back();
        size--;
        tribonacci(arr, length);
    }
    if (size != length)
    {
        int sum = arr[size - 3] + arr[size - 2] + arr[size - 1];
        arr.push_back(sum);
        tribonacci(arr, length);
    }
}

int main()
{
    vector<int> arr = {10, 20, 30};
    tribonacci(arr, 5);
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }   
    cout << "]" << "\n";
    return 0;
}
