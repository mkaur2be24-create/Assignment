#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *prev, *next;
    Node(char val)
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

    void insertAtEnd(char value)
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

    bool isPalindrome()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return false;
        }

        Node *left = head;
        Node *right = tail;

        while (left != right && right->next != left)
        {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyList list;
    string str;

    cout << "Enter string: ";
    cin >> str;

    for (char ch : str)
    {
        list.insertAtEnd(ch);
    }

    cout << "Doubly Linked List: ";
    list.display();

    if (list.isPalindrome())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
