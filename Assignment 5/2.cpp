#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertEnd(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void countAndDelete(int key)
{
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            count++;
            if (prev == NULL)
            {
                head = temp->next;
                delete temp;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Count: " << count << endl;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(3);
    insertEnd(1);

    int key = 1;
    countAndDelete(key);

    return 0;
}