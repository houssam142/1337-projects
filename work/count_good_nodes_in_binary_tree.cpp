/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_good_nodes_in_binary_tree.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:59:39 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/26 14:02:33 by hounejja         ###   ########.fr       */
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

int	count_nodes(TreeNode *root, int max_so_far)
{
	int	count;

	if (!root)
		return (0);
	count = (root->val >= max_so_far) ? 1 : 0;
	max_so_far = max(max_so_far, root->val);
	count += count_nodes(root->left, max_so_far);
	count += count_nodes(root->right, max_so_far);
	return (count);
}

int	goodNodes(TreeNode *root)
{
	return (count_nodes(root, root->val));
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
	int			count;

	root = new_node(3);
	root->left = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(2);
	count = goodNodes(root);
	cout << count << endl;
	return (0);
}
