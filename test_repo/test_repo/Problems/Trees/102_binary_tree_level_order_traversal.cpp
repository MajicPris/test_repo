#include "trees_problems_if.h"
#include <queue>

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root)
        return res;

    queue<TreeNode*> q;
    q.push(root);

    while (q.empty() == false)
    {
        vector<int> v1;
        int len = q.size();

        for(int i =0; i < len; ++i)
        {
            // Print front of queue and remove it from queue
            TreeNode* node = q.front();
            q.pop();

            v1.push_back(node->val);

            /* Enqueue left child */
            if (node->left != NULL)
                q.push(node->left);

            /*Enqueue right child */
            if (node->right != NULL)
                q.push(node->right);
        }

        res.push_back(v1);
    }
    return res;
}
