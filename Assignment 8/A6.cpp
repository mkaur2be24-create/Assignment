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

treenode *buildTree(int inorder[], int postorder[], int inStart, int inEnd, int &postIndex)
{
    if (inStart > inEnd)
        return nullptr;

    treenode *root = new treenode(postorder[postIndex]);
    postIndex--;

    if (inStart == inEnd)
        return root;

    int inIndex = searchInorder(inorder, inStart, inEnd, root->data);

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

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

    int *inorder = new int[n];
    int *postorder = new int[n];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    int postIndex = n - 1;
    treenode *root = buildTree(inorder, postorder, 0, n - 1, postIndex);

    inorderPrint(root);
    cout << endl;

    delete[] inorder;
    delete[] postorder;

    return 0;
}
