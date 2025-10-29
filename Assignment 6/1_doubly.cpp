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

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << value << " inserted at the beginning" << endl;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << value << " inserted at the end" << endl;
    }

    void insertAtTarget(int value, int target, bool before)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr && current->data != target)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Target not found" << endl;
            return;
        }

        Node *newNode = new Node(value);

        if (before)
        {
            if (current == head)
            {
                insertAtBeginning(value);
                return;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
            cout << value << " inserted before " << target << endl;
        }
        else
        {
            if (current == tail)
            {
                insertAtEnd(value);
                return;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            cout << value << " inserted after " << target << endl;
        }
    }

    void deleteSpecific(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = head;

        while (current != nullptr && current->data != value)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << value << " not found in the list" << endl;
            return;
        }

        if (current == head)
        {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
        }
        else if (current == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Node " << value << " deleted successfully" << endl;
    }

    void search(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        int pos = 1;
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << value << " found at position " << pos << endl;
                return;
            }
            current = current->next;
            pos++;
        }
        cout << value << " not found in the list" << endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
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
    int ch, value, target, c;

    while (true)
    {
        cout << "\n1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert before/after a specific node" << endl;
        cout << "4. Delete a specific node" << endl;
        cout << "5. Search for a node" << endl;
        cout << "6. Display list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter 1 to insert before target or 0 to insert after target: ";
            cin >> c;
            cout << "Enter target value: ";
            cin >> target;
            list.insertAtTarget(value, target, c);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteSpecific(value);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 6:
            list.display();
            break;

        case 7:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
