#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
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

    int parityCount(int n)
    {
        int count = 0;
        while (n)
        {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

    void removeEvenParityNodes()
    {
        Node *temp = head;
        while (temp)
        {
            int parity = parityCount(temp->data);
            if (parity % 2 == 0)
            {
                Node *toDelete = temp;
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next)
                    temp->next->prev = temp->prev;

                temp = temp->next;
                delete toDelete;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data;
            temp = temp->next;
            if (temp)
                cout << " <=> ";
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        dll.insertAtEnd(val);
    }

    dll.removeEvenParityNodes();

    cout << "After removing even parity nodes: ";
    dll.display();

    return 0;
}
