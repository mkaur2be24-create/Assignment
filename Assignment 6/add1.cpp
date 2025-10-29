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
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void splitList(CircularLinkedList &firstHalf, CircularLinkedList &secondHalf)
    {
        if (head == nullptr || head->next == head)
        {
            firstHalf.head = head;
            secondHalf.head = nullptr;
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast->next != head && fast->next->next != head)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast->next->next == head)
            fast = fast->next;

        firstHalf.head = head;
        if (head->next != head)
            secondHalf.head = slow->next;

        fast->next = slow->next;
        slow->next = head;
    }

    void display()
    {
        if (head == nullptr)
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
    CircularLinkedList list, firstHalf, secondHalf;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        list.insertAtEnd(val);
    }

    list.splitList(firstHalf, secondHalf);

    cout << "First Half: ";
    firstHalf.display();

    cout << "Second Half: ";
    secondHalf.display();

    return 0;
}
