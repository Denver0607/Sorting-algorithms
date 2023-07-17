#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int key;
    NODE *left;
    NODE *right;
};

NODE *initTree(NODE *pRoot)
{
    pRoot->left = pRoot->right = NULL;
    return pRoot;
}

// 1
NODE *createNode(int data)
{
    NODE *temp = new NODE();
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// 2
void Insert(NODE *&pRoot, int x)
{
    if (pRoot == NULL)
        pRoot = createNode(x);
    else if (x > pRoot->key)
        Insert(pRoot->right, x);
    else
        Insert(pRoot->left, x);
}

// 3
void NLR(NODE *pRoot)
{
    if (pRoot == NULL)
    {
        cout << "Tree have 0 pRoot\n";
        return;
    }
    cout << pRoot->key << " ";
    NLR(pRoot->left);
    NLR(pRoot->right);
}

// 4
void LNR(NODE *pRoot)
{
    if (pRoot == NULL)
    {
        cout << "Tree have 0 pRoot\n";
        return;
    }
    NLR(pRoot->left);
    cout << pRoot->key << " ";
    NLR(pRoot->right);
}

// 5
void LRN(NODE *pRoot)
{
    if (pRoot == NULL)
    {
        cout << "Tree have 0 pRoot\n";
        return;
    }
    NLR(pRoot->left);
    NLR(pRoot->right);
    cout << pRoot->key << " ";
}

// 7
int Height(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    int leftHeight = Height(pRoot->left);
    int rightHeight = Height(pRoot->right);

    if (leftHeight > rightHeight)
        return (leftHeight + 1);
    else
        return (rightHeight + 1);
}

// 6
void printCurrentLevel(NODE *pRoot, int level)
{
    if (pRoot == NULL)
        return;
    else if (level == 1)
        cout << pRoot->key << " ";
    else
    {
        printCurrentLevel(pRoot->left, level - 1);
        printCurrentLevel(pRoot->right, level - 1);
    }
}

void LevelOrder(NODE *pRoot)
{
    int h = Height(pRoot);
    for (int i = 1; i <= h; i++)
        printCurrentLevel(pRoot, i);
}

// 8

// print binary tree
void printBT(const string &prefix, NODE *pRoot, bool isLeft)
{
    if (pRoot != nullptr)
    {
        cout << prefix;

        cout << (isLeft ? "|---" : "\'---");

        // print the value of the node
        cout << pRoot->key << endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), pRoot->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), pRoot->right, false);
    }
}

void printBT(NODE *pRoot)
{
    printBT("", pRoot, false);
}

int main()
{
    int choice, x;
    NODE *pRoot=NULL;
    while (1)
    {
        cout << "-----------------------MENU--------------------\n";
        cout << "1. Print binary tree\n";
        cout << "2. Add a NODE with given value into a given BST\n";
        cout << "3. Pre-order traversal\n";
        cout << "4. In-order traversal\n";
        cout << "5. Post-order traversal\n";
        cout << "6. Level-order traversal\n";
        cout << "7. Calculate the height of a given Binary Tree\n";
        cout << "8. Count the number of NODE from a given Binary Tree\n";
        cout << "9. Calculate the total value of all NODEs from a given Binary Tree\n";
        cout << "10. Find and return a NODE with given value from a given Binary Search Tree\n";
        cout << "0. Exit\n";
        cout << "-----------------------------------------------\n";
        cout << "Your choice = ";
        cin >> choice;
        if (choice == 1)
        {
            printBT(pRoot);
        }
        else if (choice == 2)
        {
            cout << "Value = ";
            cin >> x;
            Insert(pRoot, x);
        }
        else if (choice == 0)
        {
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}