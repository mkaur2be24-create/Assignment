#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left, *up, *down;

    Node(int val)
    {
        data = val;
        right = left = up = down = NULL;
    }
};

Node *constructLinkedMatrix(int mat[3][3], int rows, int cols)
{
    Node *node[3][3];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            node[i][j] = new Node(mat[i][j]);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j + 1 < cols)
                node[i][j]->right = node[i][j + 1];

            if (j - 1 >= 0)
                node[i][j]->left = node[i][j - 1];

            if (i + 1 < rows)
                node[i][j]->down = node[i + 1][j];

            if (i - 1 >= 0)
                node[i][j]->up = node[i - 1][j];
        }
    }

    return node[0][0];
}

void displayLinkedMatrix(Node *head, int rows, int cols)
{
    Node *rowHead = head;

    for (int i = 0; i < rows; i++)
    {
        Node *temp = rowHead;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;

        if (rowHead)
            rowHead = rowHead->down;
    }
}

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Node *head = constructLinkedMatrix(mat, 3, 3);

    cout << "Doubly Linked List Representation (Row-wise):\n";
    displayLinkedMatrix(head, 3, 3);

    return 0;
}
