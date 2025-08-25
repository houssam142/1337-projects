/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_level_order_traversal.cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:25:01 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/24 16:16:07 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>

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

void    levelOrder_helper(TreeNode *root, vector<vector<int>> &res)
{
	queue<TreeNode *> q;
    
	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		res.push_back({});
		for (int i = 0; i < size; i++)
		{
			root = q.front();
			res[level].push_back(root->val);
			q.pop();
            if (root->left) 
				q.push(root->left);
            if (root->right)
				q.push(root->right);
        }
		level++;
	}
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> arr;

    if (!root)
        return arr;
    levelOrder_helper(root, arr);
    return arr;
}

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

int main()
{
    vector<vector<int>>arr;
    TreeNode *root = new_node(3);
    root->left = new_node(9);
    root->right = new_node(20);
    root->right->left = new_node(15);
    root->right->right = new_node(7);
    root->left->left = new_node(42);
    root->left->right = new_node(52);
    arr = levelOrder(root);
    for (vector<int> word : arr)
    {
        cout << "[";
        for (int i = 0; i < word.size(); i++)
        {
            cout << word[i];
            if (i < word.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    return 0;
}
