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

int	maxDepth(TreeNode *root)
{
	int	left_depth;
	int	right_depth;

	if (!root)
		return (0);
	left_depth = maxDepth(root->left);
	right_depth = maxDepth(root->right);
	return (max(left_depth, right_depth) + 1);
}
