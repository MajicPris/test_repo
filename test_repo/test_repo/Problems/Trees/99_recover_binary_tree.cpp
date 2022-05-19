#include "trees_problems_if.h"
#include <vector>



vector<int> v1;
int i = 0;

void inOrder(TreeNode* root)
{
	if (root != nullptr)
	{
		inOrder(root->left);
		v1.push_back(root->val);
		inOrder(root -> right);
	}
}

void recoverInOrder(TreeNode* root)
{
	if (root != nullptr)
	{
		recoverInOrder(root->left);
		if (root->val != v1.at(i))
		{
			swap(root->val, v1.at(i));
		}
		i++;
		recoverInOrder(root->right);
	}
}

void recoverTree(TreeNode* root) 
{
	inOrder(root);
	sort(v1.begin(), v1.end());
	recoverInOrder(root);
}



void testRecoverBinaryTree()
{

}
