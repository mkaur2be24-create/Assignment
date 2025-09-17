#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertBegin(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

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

void insertAfter(int val, int x)
{
    Node *temp = head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Value not found\n";
        return;
    }
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(int val, int x)
{
    if (head == NULL)
        return;
    if (head->data == val)
    {
        insertBegin(x);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Value not found\n";
        return;
    }
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBegin()
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd()
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteValue(int val)
{
    if (head == NULL)
        return;
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Value not found\n";
        return;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}

void searchNode(int val)
{
    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, val, x;
    do
    {
        cout << "\nMenu:\n";
        cout << "1.Insert at Beginning\n2.Insert at End\n3.Insert After\n4.Insert Before\n";
        cout << "5.Delete from Beginning\n6.Delete from End\n7.Delete Value\n";
        cout << "8.Search\n9.Display\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertBegin(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
            break;
        case 3:
            cout << "Enter value after which to insert: ";
            cin >> val;
            cout << "Enter new value: ";
            cin >> x;
            insertAfter(val, x);
            break;
        case 4:
            cout << "Enter value before which to insert: ";
            cin >> val;
            cout << "Enter new value: ";
            cin >> x;
            insertBefore(val, x);
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            deleteValue(val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 9:
            display();
            break;
        }
    } while (choice != 0);

    return 0;
}