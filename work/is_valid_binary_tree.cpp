/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_binary_tree.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:01:52 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/26 15:10:14 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

bool	pwd(TreeNode *root)
{
	
}

bool	helper(TreeNode *root, int root_val)
{
	bool flag;

	if (root->val > root_val)
		flag = 
	helper(root->left, root_val);
	return flag;
}

bool	func(TreeNode *root, int max_so_far)
{
	bool flag_left;
	if (!root)
		return false;
	flag_left = helper(root, max_so_far);
	bool flag_right = pwd(root);
	return (true);
}

bool	isValidBST(TreeNode *root)
{
	return (func(root, root->val));
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
	TreeNode	*root;
	bool		flag;

	root = new_node(2);
	root->left = new_node(1);
	root->right = new_node(3);
	flag = isValidBST(root);
	if (!flag)
		cout << "false" << endl;
	else
		cout << "true" << endl;
	return (0);
}
