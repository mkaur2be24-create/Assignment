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

bool searchRecursive(treenode* root, int key)
{
    if(root == nullptr)
        return false;
    if(root->data == key)
        return true;
    else if(key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

bool searchIterative(treenode* root, int key)
{
    while(root != nullptr)
    {
        if(root->data == key)
            return true;
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int findMax(treenode* root)
{
    if(root == nullptr)
        return -1;
    while(root->right != nullptr)
        root = root->right;
    return root->data;
}

int findMin(treenode* root)
{
    if(root == nullptr)
        return -1;
    while(root->left != nullptr)
        root = root->left;
    return root->data;
}

treenode* inorderSuccessor(treenode* root, treenode* node)
{
    treenode* successor = nullptr;
    while(root != nullptr)
    {
        if(node->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if(node->data > root->data)
            root = root->right;
        else
            break;
    }
    if(node->right != nullptr)
    {
        treenode* temp = node->right;
        while(temp->left != nullptr)
            temp = temp->left;
        successor = temp;
    }
    return successor;
}

treenode* inorderPredecessor(treenode* root, treenode* node)
{
    treenode* predecessor = nullptr;
    while(root != nullptr)
    {
        if(node->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else if(node->data < root->data)
            root = root->left;
        else
            break;
    }
    if(node->left != nullptr)
    {
        treenode* temp = node->left;
        while(temp->right != nullptr)
            temp = temp->right;
        predecessor = temp;
    }
    return predecessor;
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

    cout << "Recursive Search for 40: " << (searchRecursive(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Iterative Search for 90: " << (searchIterative(root, 90) ? "Found" : "Not Found") << endl;

    cout << "Maximum element: " << findMax(root) << endl;
    cout << "Minimum element: " << findMin(root) << endl;

    treenode* node = root->right;
    treenode* succ = inorderSuccessor(root, node);
    treenode* pred = inorderPredecessor(root, node);

    if(succ)
        cout << "Inorder Successor of " << node->data << " is: " << succ->data << endl;
    else
        cout << "No Successor for " << node->data << endl;

    if(pred)
        cout << "Inorder Predecessor of " << node->data << " is: " << pred->data << endl;
    else
        cout << "No Predecessor for " << node->data << endl;

    return 0;
}
