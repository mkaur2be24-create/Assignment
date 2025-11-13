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

class dllnode
{
public:
    int data;
    dllnode *prev, *next;

    dllnode(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

void bstToDLL(treenode *root, dllnode *&head, dllnode *&tail)
{
    if (root == nullptr)
        return;

    bstToDLL(root->left, head, tail);

    dllnode *newnode = new dllnode(root->data);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    bstToDLL(root->right, head, tail);
}

dllnode *mergeDLL(dllnode *h1, dllnode *h2)
{
    dllnode *head = nullptr, *tail = nullptr;

    while (h1 != nullptr && h2 != nullptr)
    {
        dllnode *pick;
        if (h1->data < h2->data)
        {
            pick = h1;
            h1 = h1->next;
        }
        else
        {
            pick = h2;
            h2 = h2->next;
        }

        pick->prev = pick->next = nullptr;
        if (head == nullptr)
        {
            head = pick;
            tail = pick;
        }
        else
        {
            tail->next = pick;
            pick->prev = tail;
            tail = pick;
        }
    }

    while (h1 != nullptr)
    {
        dllnode *pick = h1;
        h1 = h1->next;
        pick->prev = pick->next = nullptr;

        if (head == nullptr)
        {
            head = pick;
            tail = pick;
        }
        else
        {
            tail->next = pick;
            pick->prev = tail;
            tail = pick;
        }
    }

    while (h2 != nullptr)
    {
        dllnode *pick = h2;
        h2 = h2->next;
        pick->prev = pick->next = nullptr;

        if (head == nullptr)
        {
            head = pick;
            tail = pick;
        }
        else
        {
            tail->next = pick;
            pick->prev = tail;
            tail = pick;
        }
    }

    return head;
}

void printDLL(dllnode *head)
{
    while (head != nullptr)
    {
        cout << head->data << " <--> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main()
{
    treenode *T1 = new treenode(20);
    T1->left = new treenode(10);
    T1->right = new treenode(30);
    T1->left->left = new treenode(25);
    T1->right->right = new treenode(100);

    treenode *T2 = new treenode(50);
    T2->left = new treenode(5);
    T2->right = new treenode(70);

    dllnode *h1 = nullptr, *t1 = nullptr;
    dllnode *h2 = nullptr, *t2 = nullptr;

    bstToDLL(T1, h1, t1);
    bstToDLL(T2, h2, t2);

    dllnode *merged = mergeDLL(h1, h2);

    printDLL(merged);

    return 0;
}
