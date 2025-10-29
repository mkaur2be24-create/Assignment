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

class CircularList
{
    Node *head, *tail;

public:
    CircularList()
    {
        head = tail = nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    int findSize()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node *current = head;
        while (true)
        {
            count++;
            current = current->next;
            if (current == head)
                break;
        }
        return count;
    }

    void display()
    {
        if (head == nullptr)
            return;
        Node *current = head;
        while (true)
        {
            cout << current->data << " ";
            current = current->next;
            if (current == head)
                break;
        }
    }
};

int main()
{
    CircularList list;
    int n, value;

    cout << "\nEnter number of nodes for Circular Linked List: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Circular Linked List: ";
    list.display();
    cout << "\nSize of Circular Linked List: " << list.findSize() << endl;

    return 0;
}
