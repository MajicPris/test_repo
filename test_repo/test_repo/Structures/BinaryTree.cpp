#include "BinaryTree.h"
#include <time.h>

using namespace std;

// Вывод узлов дерева (обход в инфиксной форме)
void treeprint(tnode* tree)
{
    if (tree != nullptr) {      //Пока не встретится пустой узел
        treeprint(tree->left);  //Рекурсивная функция вывода левого поддерева
        cout << tree->field << " "; //Отображаем корень дерева
        treeprint(tree->right); //Рекурсивная функция вывода правого поддерева
    }
}
// Добавление узлов в дерево
struct tnode* addnode(int x, tnode* tree) 
{
    if (tree == nullptr)     // Если дерева нет, то формируем корень
    {
        tree = new tnode; //память под узел
        tree->field = x;   //поле данных
        tree->left = nullptr;
        tree->right = nullptr; //ветви инициализируем пустотой
    }
    else     // иначе
        if (x < tree->field)   //Если элемент x меньше корневого, уходим влево
            tree->left = addnode(x, tree->left); //Рекурсивно добавляем элемент
        else  //иначе уходим вправо
            tree->right = addnode(x, tree->right); //Рекурсивно добавляем элемент
    return(tree);
}
//Освобождение памяти дерева
void freemem(tnode* tree)
{
    if (tree != nullptr)    // если дерево не пустое
    {
        freemem(tree->left);   // рекурсивно удаляем левую ветку
        freemem(tree->right);  // рекурсивно удаляем правую ветку
        delete tree;           // удаляем корень
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