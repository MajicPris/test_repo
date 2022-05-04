#include <iostream>

// ��������� - ���� ������
struct tnode
{
    int field;           // ���� ������
    struct tnode* left;  // ����� �������
    struct tnode* right; // ������ �������
};

void treeprint(tnode* tree);

struct tnode* addnode(int x, tnode* tree);

void freemem(tnode* tree);

void testBinaryTree();