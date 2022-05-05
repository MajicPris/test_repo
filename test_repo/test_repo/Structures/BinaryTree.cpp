#include "BinaryTree.h"
#include <time.h>

using namespace std;

// ����� ����� ������ (����� � ��������� �����)
void treeprint(tnode* tree)
{
    if (tree != nullptr) {      //���� �� ���������� ������ ����
        treeprint(tree->left);  //����������� ������� ������ ������ ���������
        cout << tree->field << " "; //���������� ������ ������
        treeprint(tree->right); //����������� ������� ������ ������� ���������
    }
}
// ���������� ����� � ������
struct tnode* addnode(int x, tnode* tree) 
{
    if (tree == nullptr)     // ���� ������ ���, �� ��������� ������
    {
        tree = new tnode; //������ ��� ����
        tree->field = x;   //���� ������
        tree->left = nullptr;
        tree->right = nullptr; //����� �������������� ��������
    }
    else     // �����
        if (x < tree->field)   //���� ������� x ������ ���������, ������ �����
            tree->left = addnode(x, tree->left); //���������� ��������� �������
        else  //����� ������ ������
            tree->right = addnode(x, tree->right); //���������� ��������� �������
    return(tree);
}
//������������ ������ ������
void freemem(tnode* tree)
{
    if (tree != nullptr)    // ���� ������ �� ������
    {
        freemem(tree->left);   // ���������� ������� ����� �����
        freemem(tree->right);  // ���������� ������� ������ �����
        delete tree;           // ������� ������
    }
}

void testBinaryTree()
{
    std::cout << "\n testBinaryTree" << std::endl;
    struct tnode* root = 0;    // tree struct
    //srand(time(0));
    for (int i = 0; i < 8; i++)
    {
        root = addnode(rand(), root); // add node
    }
    treeprint(root); 
    freemem(root);  
    std::cout << std::endl;
}