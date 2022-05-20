#include "trees_problems_if.h"
#include <queue>


TreeNode* invertTree(TreeNode* root)
{
    if (root == NULL)
        return root;

    // Create an empty queue for level order traversal
    queue<TreeNode*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) 
    {
        // Print front of queue and remove it from queue
        TreeNode* node = q.front();
        //cout << node->data << " ";
        q.pop();
        swap(node->left, node->right);
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
    return root;
}