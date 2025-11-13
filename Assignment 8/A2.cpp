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

treenode **generateTreesUtil(int start, int end, int &count)
{
    if (start > end)
    {
        count = 1;
        treenode **arr = new treenode *[1];
        arr[0] = nullptr;
        return arr;
    }

    treenode **result = new treenode *[500];
    count = 0;

    for (int i = start; i <= end; i++)
    {
        int leftCount, rightCount;
        treenode **leftTrees = generateTreesUtil(start, i - 1, leftCount);
        treenode **rightTrees = generateTreesUtil(i + 1, end, rightCount);

        for (int l = 0; l < leftCount; l++)
        {
            for (int r = 0; r < rightCount; r++)
            {
                treenode *root = new treenode(i);
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                result[count++] = root;
            }
        }

        delete[] leftTrees;
        delete[] rightTrees;
    }

    return result;
}

treenode **generateTrees(int n, int &count)
{
    if (n == 0)
    {
        count = 0;
        return nullptr;
    }
    return generateTreesUtil(1, n, count);
}

void preorder(treenode *root)
{
    if (root == nullptr)
    {
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    int count;
    treenode **trees = generateTrees(n, count);

    cout << "Unique BSTs (preorder):" << endl;
    for (int i = 0; i < count; i++)
    {
        preorder(trees[i]);
        cout << endl;
    }

    delete[] trees;
    return 0;
}
