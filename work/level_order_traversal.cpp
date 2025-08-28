/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_order_traversal.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:15:33 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/26 08:51:23 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	levelOrder_1(TreeNode *root, int level, vector<vector<int>> &arr)
{
	if (!root)
		return ;
	if (level >= arr.size())
		arr.push_back({});
	arr[level].push_back(root->val);
	levelOrder_1(root->left, level + 1, arr);
	levelOrder_1(root->right, level + 1, arr);
}
vector<vector<int>> levelOrder(TreeNode *root)
{
	vector<vector<int>> arr;
	if (!root)
		return (arr);
	arr.push_back({});
	levelOrder_1(root, 0, arr);
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

void	print(TreeNode *node)
{
	if (!node)
		return ;
	print(node->right);
	print(node->left);
	cout << node->val << "\n";
}

int	main(void)
{
	TreeNode	*root;

	vector<vector<int>> after;
	root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);
	after = levelOrder(root);
	for (vector<int> word : after)
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
