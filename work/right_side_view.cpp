/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_side_view.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:56:57 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/14 09:18:06 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "max_depth_binary_tree.cpp"
#include <algorithm>
#include <queue>
#include <vector>

using namespace	std;

void	func(TreeNode *root, vector<int> &arr, int start, int &max_level)
{
	if (!root)
		return ;
	if (start > max_level)
	{
		arr.push_back(root->val);
		max_level = start;
	}
	func(root->right, arr, start + 1, max_level);
	func(root->left, arr, start + 1, max_level);
}

vector<int> rightSideView(TreeNode *root)
{
	int	max_level;

	vector<int> arr;
	max_level = -1;
	if (!root)
		return (arr);
	func(root, arr, 0, max_level);
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
	TreeNode	*root;

	vector<int> arr;
	root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	// root->right->left = new_node(15);
	// root->right->right = new_node(7);
	// root->left->left = new_node(42);
	// root->left->right = new_node(52);
	arr = rightSideView(root);
	cout << "[";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
		if (i < arr.size() - 1)
			cout << ", ";
	}
	cout << "] ";
	return (0);
}
