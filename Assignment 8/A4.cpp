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

void rightViewUtil(treenode *root, int level, int &maxLevel)
{
    if (root == nullptr)
        return;

    if (level > maxLevel)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        int *vals = new int[n];
        for (int i = 0; i < n; i++)
            cin >> vals[i];

        treenode **nodes = new treenode *[n];
        for (int i = 0; i < n; i++)
        {
            if (vals[i] == -1)
                nodes[i] = nullptr;
            else
                nodes[i] = new treenode(vals[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (nodes[i] == nullptr)
                continue;
            int li = 2 * i + 1;
            int ri = 2 * i + 2;
            if (li < n)
                nodes[i]->left = nodes[li];
            if (ri < n)
                nodes[i]->right = nodes[ri];
        }

        treenode *root = nodes[0];

        int maxLevel = 0;
        rightViewUtil(root, 1, maxLevel);
        cout << endl;

        for (int i = 0; i < n; i++)
            delete nodes[i];
        delete[] nodes;
        delete[] vals;
    }

    return 0;
}
