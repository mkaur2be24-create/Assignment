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

bool isLeaf(treenode* node)
{
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}

int sumOfLeftLeaves(treenode* root)
{
    if(root == nullptr)
        return 0;
    int sum = 0;
    if(isLeaf(root->left))
        sum += root->left->data;
    else
        sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}

int main()
{
    treenode* root = new treenode(3);
    root->left = new treenode(9);
    root->right = new treenode(20);
    root->right->left = new treenode(15);
    root->right->right = new treenode(7);

    cout << "Sum of all left leaves: " << sumOfLeftLeaves(root) << endl;

    return 0;
}
