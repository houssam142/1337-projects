/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLetterCombinations.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 01:21:30 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/16 02:12:00 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>

using namespace std;


void getCombinations(vector<string> &res, string digits, int index)
{
	static string path;
	vector<string> tel = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int digit = digits[index] - '0';
	if (index == digits.size())
	{
		res.push_back(path);
		return ;
	}
	for (char c: tel[digit])
	{
		path.push_back(c);	
		getCombinations(res, digits, index + 1);
		path.pop_back();
	}
}
vector<string> letterCombinations(string digits)
{
	vector<string> res;
	if (digits.size() == 0)
		return res;
	getCombinations(res, digits, 0);
	return res;
}

int main()
{
	string digits = "23";
	vector<string> res = letterCombinations(digits);
	cout << "[";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << ", ";
	}
	cout << "]";
	return 0;
}
