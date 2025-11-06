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

treenode* insert(treenode* root, int val)
{
    if(root == nullptr)
        return new treenode(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    return root;
}

treenode* findMin(treenode* node)
{
    while(node->left != nullptr)
        node = node->left;
    return node;
}

treenode* deleteNode(treenode* root, int val)
{
    if(root == nullptr)
        return root;
    if(val < root->data)
        root->left = deleteNode(root->left, val);
    else if(val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        if(root->left == nullptr)
        {
            treenode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            treenode* temp = root->left;
            delete root;
            return temp;
        }
        treenode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(treenode* root)
{
    if(root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if(leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int minDepth(treenode* root)
{
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return 1;
    if(root->left == nullptr)
        return 1 + minDepth(root->right);
    if(root->right == nullptr)
        return 1 + minDepth(root->left);
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    if(leftDepth < rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

void inorder(treenode* root)
{
    if(root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    treenode* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 70);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
