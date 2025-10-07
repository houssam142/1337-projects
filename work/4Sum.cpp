/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4Sum.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:45:36 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/01 17:43:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    std::vector<std::vector<int>> res;
    int sum;
    int left;
    int right;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        
    }
    return res;
}

int main()
{
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> arr = fourSum(nums, 0);
    for (std::vector<int> w : arr)
    {
        std::cout << "[";
        for (int i = 0; i < w.size(); i++)
        {
            std::cout << w[i];
            if (i != w.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << '\n';
    }
    return 0;
}
