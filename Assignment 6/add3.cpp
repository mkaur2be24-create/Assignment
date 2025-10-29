#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
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
        if (!head)
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

    Node *reverseKGroup(Node *head, int k)
    {
        if (!head)
            return NULL;

        Node *current = head, *nextNode = NULL, *prevNode = NULL;
        int count = 0;

        while (current && count < k)
        {
            nextNode = current->next;
            current->next = prevNode;
            current->prev = nextNode;
            prevNode = current;
            current = nextNode;
            count++;
        }

        if (nextNode)
        {
            head->next = reverseKGroup(nextNode, k);
            if (head->next)
                head->next->prev = head;
        }

        return prevNode;
    }

    void reverseInGroups(int k)
    {
        head = reverseKGroup(head, k);
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " <=> ";
            temp = temp->next;
        }
        cout << " <=> NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        dll.insertAtEnd(val);
    }

    cout << "Enter group size (k): ";
    cin >> k;

    cout << "\nOriginal List: ";
    dll.display();

    dll.reverseInGroups(k);

    cout << "Reversed in groups of " << k << ": ";
    dll.display();

    return 0;
}
