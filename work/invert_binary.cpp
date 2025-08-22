/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_binary.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:10:14 by houssam           #+#    #+#             */
/*   Updated: 2025/08/21 20:23:05 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// class Solution
// {
// 	public:
// };

TreeNode* invertTree(TreeNode* root)
{
	TreeNode *tmp = root->left;
	
	root->left = root->right;
	root->right = tmp;
	return (root);
}
TreeNode*	new_node(int val)
{
	TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
	if (!root)
		return nullptr;
	root->val = val;
	root->left = nullptr;
	root->right = nullptr;
	return (root);
}

int main()
{
	TreeNode *root;
	TreeNode *new_root;

	root = new_node(4);
	root->right = new_node(1);
	root->left = new_node(2);
	new_root = invertTree(root);
	cout << new_root->right->val << endl;
}
