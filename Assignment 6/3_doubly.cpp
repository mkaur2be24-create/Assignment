#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyList
{
    Node *head, *tail;

public:
    DoublyList()
    {
        head = tail = nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int findSize()
    {
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    DoublyList list;
    int n, value;

    cout << "Enter number of nodes for Doubly Linked List: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Doubly Linked List: ";
    list.display();
    cout << "\nSize of Doubly Linked List: " << list.findSize() << endl;
    return 0;
}
