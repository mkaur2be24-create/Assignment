#include <iostream>
using namespace std;

class treenode
{
public:
    int data;
    treenode *left, *right;

    treenode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool inorderCheck(treenode* root, int &prev)
{
    if(root == nullptr)
        return true;
    if(!inorderCheck(root->left, prev))
        return false;
    if(root->data <= prev)
        return false;
    prev = root->data;
    return inorderCheck(root->right, prev);
}

bool isBST(treenode* root)
{
    int prev = -100000;
    return inorderCheck(root, prev);
}

int main()
{
    treenode* root = new treenode(50);
    root->left = new treenode(30);
    root->right = new treenode(70);
    root->left->left = new treenode(20);
    root->left->right = new treenode(40);
    root->right->left = new treenode(60);
    root->right->right = new treenode(80);

    if(isBST(root))
        cout << "The given tree is a BST" << endl;
    else
        cout << "The given tree is not a BST" << endl;

    return 0;
}
