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

int maxDepth(treenode* root)
{
    if(root == nullptr)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n <= 0)
        {
            cout << 0 << endl;
            continue;
        }
        int *vals = new int[n];
        for(int i = 0; i < n; i++)
            cin >> vals[i];

        treenode **nodes = new treenode*[n];
        for(int i = 0; i < n; i++)
        {
            if(vals[i] == -1)
                nodes[i] = nullptr;
            else
                nodes[i] = new treenode(vals[i]);
        }

        for(int i = 0; i < n; i++)
        {
            if(nodes[i] == nullptr) continue;
            int li = 2*i + 1;
            int ri = 2*i + 2;
            if(li < n) nodes[i]->left = nodes[li];
            if(ri < n) nodes[i]->right = nodes[ri];
        }

        treenode* root = nodes[0];
        cout << maxDepth(root) << endl;

        for(int i = 0; i < n; i++)
            delete nodes[i];
        delete[] nodes;
        delete[] vals;
    }
    return 0;
}
