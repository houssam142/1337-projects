#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root)
{
    if (!root)
        return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);   
    return max(left_depth, right_depth) + 1;
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
    int count = 0;
    TreeNode *root = new_node(3);
    root->left = new_node(9);
    root->right = new_node(20);
    root->right->left = new_node(15);
    root->right->right = new_node(4);
    count = maxDepth(root);
    // print(root);
    cout << "count is: " << count << endl;
}
