/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zigzagLevelOrder.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 08:21:04 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/26 13:11:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <vector>

using namespace	std;

struct			TreeNode
{
	int			val;
	TreeNode	*left;
	TreeNode	*right;
	TreeNode() : val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
		right(right)
	{
	}
};

void	zigzzagLevelOrder_helper(TreeNode *root, vector<vector<int>> &arr)
{
	int			level;
	bool		flag;
	int			size;
	TreeNode	*node;
	TreeNode	*node;

	deque<TreeNode *> dq;
	level = 0;
	flag = false;
	dq.push_back(root);
	while (!dq.empty())
	{
		size = dq.size();
		arr.push_back({});
		for (int i = 0; i < size; i++)
		{
			if (!flag)
			{
				node = dq.front();
				dq.pop_front();
				arr[level].push_back(node->val);
				if (node->left)
					dq.push_back(node->left);
				if (node->right)
					dq.push_back(node->right);
			}
			else
			{
				node = dq.back();
				arr[level].push_back(node->val);
				dq.pop_back();
				if (node->right)
					dq.push_front(node->right);
				if (node->left)
					dq.push_front(node->left);
			}
		}
		flag = !flag;
		level++;
	}
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int>> arr;
	if (!root)
		return (arr);
	zigzzagLevelOrder_helper(root, arr);
	return (arr);
}

TreeNode	*new_node(int val)
{
	TreeNode	*node;

	node = (TreeNode *)malloc(sizeof(TreeNode));
	if (!node)
		return (nullptr);
	node->val = val;
	node->left = nullptr;
	node->right = nullptr;
	return (node);
}

int	main(void)
{
	vector<vector<int>> arr;
	TreeNode *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->right->right = new_node(5);
	arr = zigzagLevelOrder(root);
	for (vector<int> word : arr)
	{
		cout << "[";
		for (int i = 0; i < word.size(); i++)
		{
			cout << word[i];
			if (i < word.size() - 1)
				cout << ", ";
		}
		cout << "] ";
	}
	return (0);
}