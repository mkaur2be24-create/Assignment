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

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
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
        if (!head)
            return;

        Node *curr = head, *prev = nullptr;
        do
        {
            int parity = parityCount(curr->data);
            if (parity % 2 == 0)
            {
                if (curr == head && curr->next == head)
                {
                    delete curr;
                    head = nullptr;
                    return;
                }
                if (curr == head)
                {
                    Node *temp = head;
                    while (temp->next != head)
                        temp = temp->next;
                    temp->next = head->next;
                    Node *del = head;
                    head = head->next;
                    curr = head;
                    delete del;
                }
                else
                {
                    prev->next = curr->next;
                    Node *del = curr;
                    curr = curr->next;
                    delete del;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        } while (curr != head && head != nullptr);
    }

    void display()
    {
        if (!head)
            return;

        Node *temp = head;
        do
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != head)
                cout << " -> ";
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    CircularLinkedList cll;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        cll.insertAtEnd(val);
    }

    cll.removeEvenParityNodes();

    cout << "After removing even parity nodes: ";
    cll.display();

    return 0;
}
