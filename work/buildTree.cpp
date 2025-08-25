/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildTree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:33:46 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/25 19:59:18 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

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

TreeNode *new_node(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (!node)
        return nullptr;
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

class Solution {
private:
    int preorder_index;
    unordered_map<int, int> mapping;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++)
            mapping[inorder[i]] = i;
        
        preorder_index = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
private:
    TreeNode *build(vector<int> &preorder, int start, int end)
    {
        if (start > end)
            return nullptr;
        int root_val = preorder[preorder_index++];
        TreeNode *root = new TreeNode(root_val);
        int mid = mapping[root_val];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1,  end);

        return root;
    }
};

void	binary_inorder(vector<int> &inorder, TreeNode *root)
{
	if (!root)
		return ;
	binary_inorder(inorder, root->left);
	inorder.push_back(root->val);
	binary_inorder(inorder, root->right);
}

void    binary_pre_order(vector<int> &pre_order, TreeNode *root)
{
    if (!root)
		return ;
	pre_order.push_back(root->val);
    binary_pre_order(pre_order, root->left);
    binary_pre_order(pre_order, root->right);
}

void    print(TreeNode *node)
{
    if (!node)
        return ;
    cout << node->val << ", ";
    print(node->left);
    print(node->right);
}

int main()
{
    vector<int> pre_order;
    vector<int> inorder;
	TreeNode *new_root;
	TreeNode *root = new_node(3);
    root->left = new_node(9);
    root->right = new_node(20);
    root->right->left = new_node(15);
    root->right->right = new_node(7);
	// root->left->left = new_node(4);

    binary_pre_order(pre_order, root);
	binary_inorder(inorder, root);
	new_root = buildTree(pre_order, inorder);
	if (!new_root)
		return 1;
	cout << "inorder is: ";
	for (int num : inorder)
		cout << num << ", ";
	cout << "\n" << "preorder is: ";
	for (int num : pre_order)
		cout << num << ", ";
    cout << "\n" << "the binary tree: ";
    print(new_root);
	// cout << new_root->right->val;
    cout << endl;
}
