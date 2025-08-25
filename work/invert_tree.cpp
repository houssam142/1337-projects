/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_tree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:06:21 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/25 09:06:43 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

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

TreeNode* invertTree(TreeNode* root)
{
   if (!root)
      return nullptr;
   TreeNode *tmp = root->left;

   root->left = root->right;
   root->right = tmp;
   invertTree(root->left);
   invertTree(root->right);
   return root;
}

TreeNode *new_node(int val)
{
   TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
   if (!node)
      return nullptr;
   node->val = val;
   node->left = nullptr;
   node->right = nullptr;
   return (node);
}

void    print(TreeNode *node)
{
    if (!node)
        return ;
    print(node->right);
    print(node->left);
    cout << node->val << "\n";
}

int main()
{
   TreeNode *root = new_node(1);
   root->left = new_node(2);
   root->right = nullptr;
   root->left->left = new_node(35);
   // TreeNode *after = invertTree(root);
   print(root);
   // cout << root->left->left->val << endl;
}