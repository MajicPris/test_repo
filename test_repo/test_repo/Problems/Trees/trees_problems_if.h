#include <iostream>
#include <algorithm>
using namespace std;

#ifndef  TREES_PROBLEMS_IF
#define  TREES_PROBLEMS_IF



struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void testRecoverBinaryTree();


#endif // ! TREES_PROBLEMS_IF