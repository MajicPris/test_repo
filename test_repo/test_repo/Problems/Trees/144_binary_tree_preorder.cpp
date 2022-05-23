#include "trees_problems_if.h"
#include <stack>

vector<int> res;
vector<int> preorderTraversal(TreeNode* root) 
{
	if (root == nullptr)
	{
		return res;
	}

	stack<TreeNode*> sT;
	sT.push(root);

	while (sT.empty() == false)
	{
		TreeNode* tmp = sT.top();
		sT.pop();
		res.push_back(tmp->val);
		if (tmp->right)
			sT.push(tmp->right);
		if (tmp->left)
			sT.push(tmp->left);
		
	}
	return res;
}
