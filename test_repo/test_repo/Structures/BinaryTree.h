#include <iostream>

// Структура - узел дерева
struct tnode
{
    int field;           // поле данных
    struct tnode* left;  // левый потомок
    struct tnode* right; // правый потомок
};

void treeprint(tnode* tree);

struct tnode* addnode(int x, tnode* tree);

void freemem(tnode* tree);

void testBinaryTree();