// Inorder Traversal(L N R)

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->val, ans);
    inorder(root->right, ans);
}