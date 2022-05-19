#include "test_problems_if.h"
#include<vector>

/*

Дано дерево с выделенным корнем.
Далее приходит K запросов, каждый запрос - целое неотрицательное число, расстояние от корня.
Для каждого запроса нужно найти сумму элементов в дереве на расстоянии от корня.

Node* root = ...;

Handler h;
h.init(root);
while (k-- > 0) {
    h.sum(...);
}


     1
  2     3
4   5 6   7

0 - 1
1 - 5
2 - 22

[1, 5, 22]

sum(5)

*/

struct Node {
    int value;
    Node* l;
    Node* r;
};

class Handler 
{
public:
    vector<int> sumV;

    void init(Node* root)
    {
        calculateSum(root, 0);
    }

    int sum (size_t level)
    {
        return sumV.at(level);
    }

    void calculateSum(Node* root, int level)
    {
        if (root == nullptr)
            return;

        sumV[level] += root->value;
        calculateSum(root->l, level + 1);
        calculateSum(root->r, level + 1);
    }
};