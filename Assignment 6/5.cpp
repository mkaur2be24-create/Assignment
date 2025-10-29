#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void makeCircular()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = head;
    }

    bool isCircular()
    {
        if (head == nullptr)
            return false;

        Node *temp = head->next;

        while (temp != nullptr && temp != head)
        {
            temp = temp->next;
        }

        return (temp == head);
    }

    void display()
    {
        Node *temp = head;
        int count = 0; 
        while (temp != nullptr && count < 10)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << "..." << endl;
    }
};

int main()
{
    LinkedList list;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> val;
        list.insertAtEnd(val);
    }

    char choice;
    cout << "Make list circular? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
        list.makeCircular();

    if (list.isCircular())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
