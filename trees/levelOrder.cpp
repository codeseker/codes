// Level Order or BFS

void levelOrder(TreeNode *root, vector<int> &ans)
{
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        ans.push_back(node->val);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}