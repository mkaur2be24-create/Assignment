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

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
        tail->next = head;
        cout << value << " inserted at the beginning " << endl;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
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
        cout << value << " inserted at the end" << endl;
    }

    void insertAtTarget(int value, int target, bool before)
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *newNode = new Node(value);
        if (before)
        {
            if (head->data == target)
            {
                insertAtBeginning(value);
                return;
            }
            Node *current = head;
            while (current->next->data != target)
            {
                current = current->next;
                if (current == tail)
                {
                    cout << "Target value not found in list" << endl;
                    return;
                }
            }
            newNode->next = current->next;
            current->next = newNode;
            cout << value << " inserted at target" << endl;
        }
        else
        {
            if (tail->data == target)
            {
                insertAtEnd(value);
                return;
            }
            Node *current = head;
            while (current->data != target)
            {
                current = current->next;
                if (current == tail)
                {
                    cout << "Target value not found in list" << endl;
                    return;
                }
            }
            newNode->next = current->next;
            current->next = newNode;
            cout << value << " inserted at target" << endl;
        }
    }

    void deleteFromBeginning()
    {
        if (tail == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        cout << "Element deleted from beginning" << endl;
    }

    void deleteFromEnd()
    {
        if (tail == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            current->next = head;
            tail = current;
            delete temp;
        }
        cout << "Element deleted from end" << endl;
    }

    void deleteSpecific(int value)
    {
        if (tail == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (head->data == value)
        {
            deleteFromBeginning();
        }
        else if (tail->data == value)
        {
            deleteFromEnd();
        }
        else
        {
            Node *current = head;
            while (current->next->data != value)
            {
                current = current->next;
                if (current->next == tail)
                {
                    cout << "Value not found in list" << endl;
                    return;
                }
            }
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Element deleted" << endl;
        }
    }

    void search(int value)
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        int pos = 1;
        Node *current = head;
        while (1)
        {
            if (current->data == value)
            {
                cout << value << " found at position " << pos << endl;
                return;
            }
            pos++;
            if (current->next == head)
            {
                cout << value << " not found in the list" << endl;
                return;
            }
            current = current->next;
        }
    }

    void display()
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = head;
        while (1)
        {
            cout << current->data << " -> ";
            current = current->next;
            if (current == head)
                return;
        }
    }
};

int main()
    {
        CircularList list;
        int ch, value;
        while (true)
        {
            cout << "\n1. Insert at the beginning" << endl;
            cout << "2. Insert at the end" << endl;
            cout << "3. Insert in between" << endl;
            cout << "4. Delete from the beginning" << endl;
            cout << "5. Delete from the end" << endl;
            cout << "6. Delete specific element" << endl;
            cout << "7. Search element" << endl;
            cout << "8. Display List" << endl;
            cout << "9. Exit" << endl;
            cout << "Enter your choice" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Enter the value " << endl;
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter the value " << endl;
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter the value to be inserted" << endl;
                cin >> value;
                cout << "Enter 1 to insert before the target or 0 to insert after the target " << endl;
                int c, target;
                cin >> c;
                cout << "Enter the target" << endl;
                cin >> target;
                list.insertAtTarget(value, target, c);
                break;

            case 4:
                list.deleteFromBeginning();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter the value to be deleted" << endl;
                cin >> value;
                list.deleteSpecific(value);
                break;

            case 7:
                cout << "Enter the value to be searched" << endl;
                cin >> value;
                list.search(value);
                break;

            case 8:
                list.display();
                break;

            case 9:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Wrong input" << endl;
                break;
            }
        }
    }