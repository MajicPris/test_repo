#include "BinaryTree.h"
#include <time.h>
#include <queue>

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

tnode* createNode(int value)
{
    tnode* node = new tnode;
    node->field = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

tnode* searchNode(tnode* root, int a_index)
{
    if (root == nullptr || root->field == a_index)
    {
        return root;
    }

    if (root->field < a_index)
        return searchNode(root->right, a_index);

    return searchNode(root->left, a_index);
}

int height(tnode* root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
        {
            return lheight + 1;
        }
        else
        {
            return rheight + 1;
        }

    }
}

void BFS(tnode* root)
{
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<tnode*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        tnode* node = q.front();
        cout << node->field << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

void testBinaryTree()
{
    std::cout << "\n testBinaryTree" << std::endl;
    struct tnode* root = nullptr;    // tree struct
    srand(time(0));
    for (int i = 0; i < 8; i++)
    {
        root = addnode(i+4, root); // add node
    }
    treeprint(root);

    tnode* tmp = searchNode(root, 4);
    if (tmp)
    {
        cout << "DONEEE";

        tmp->field = 2;
    }
    treeprint(root);
    freemem(root);  
    std::cout << std::endl;

    /*----------------------------------------------------------------*/
    tnode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);
}
