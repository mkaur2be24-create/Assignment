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

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = head;
        while (true)
        {
            cout << current->data << " ";
            current = current->next;
            if (current == head)
                break;
        }
        cout << head->data << endl; 
    }
};

int main()
{
    CircularList list;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Circular Linked List: ";
    list.display();

    return 0;
}
