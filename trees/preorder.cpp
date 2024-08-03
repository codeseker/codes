// Preorder Traversal(N L R)

void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->val, ans);
    preorder(root->left, ans);
    preorder(root->right, ans);
}