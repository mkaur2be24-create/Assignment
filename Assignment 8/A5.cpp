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

int searchInorder(int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == value)
            return i;
    return -1;
}

treenode *buildTree(int preorder[], int inorder[], int inStart, int inEnd, int &preIndex)
{
    if (inStart > inEnd)
        return nullptr;

    treenode *root = new treenode(preorder[preIndex]);
    preIndex++;

    if (inStart == inEnd)
        return root;

    int inIndex = searchInorder(inorder, inStart, inEnd, root->data);

    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void inorderPrint(treenode *root)
{
    if (root == nullptr)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int n;
    cin >> n;

    int *preorder = new int[n];
    int *inorder = new int[n];

    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    int preIndex = 0;
    treenode *root = buildTree(preorder, inorder, 0, n - 1, preIndex);

    inorderPrint(root);
    cout << endl;

    delete[] preorder;
    delete[] inorder;

    return 0;
}
