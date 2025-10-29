#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node *random;

    Node(int val)
    {
        data = val;
        next = prev = random = NULL;
    }
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void setRandom(int fromVal, int toVal)
    {
        Node *from = head, *to = head;
        while (from && from->data != fromVal)
            from = from->next;
        while (to && to->data != toVal)
            to = to->next;

        if (from && to)
            from->random = to;
    }

    void correctRandomPointer()
    {
        if (!head)
            return;

        Node *temp = head;
        while (temp)
        {
            if (temp->random && temp->random != temp->next && temp->random != temp->prev)
            {
                temp->random = temp->next;
            }
            temp = temp->next;
        }
    }

    void display()
    {
        Node *temp = head;
        cout << "List: ";
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " <=> ";
            temp = temp->next;
        }
        cout << " <=> NULL" << endl;
    }

    void displayRandoms()
    {
        Node *temp = head;
        cout << "Random Pointers:" << endl;
        while (temp)
        {
            cout << "Node " << temp->data << " -> ";
            if (temp->random)
                cout << temp->random->data;
            else
                cout << "NULL";
            cout << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);

    dll.setRandom(1, 2);
    dll.setRandom(2, 1);

    cout << "Before correction:" << endl;
    dll.display();
    dll.displayRandoms();

    dll.correctRandomPointer();

    cout << "\nAfter correction:" << endl;
    dll.display();
    dll.displayRandoms();

    return 0;
}
