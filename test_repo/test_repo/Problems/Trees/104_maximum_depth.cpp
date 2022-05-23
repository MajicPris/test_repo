#include "trees_problems_if.h"

int maxDepth(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);

    if (lheight > rheight)
    {
        return lheight + 1;
    }
    else
    {
        return rheight + 1;
    }
}

void testMaxDepth()
{
    cout << "\n===============testMaxDepth===============" << endl;

}