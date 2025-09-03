#include <iostream>
using namespace std;
#define SIZE 5
class Queue
{
    int arr[SIZE];
    int front, rear;

public:
    void init()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return (rear == SIZE - 1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1)
            front = 0; 
        arr[++rear] = value;
        cout << value << " inserted into queue" << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[front] << " removed from queue\n";
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Front element is: " << arr[front] << endl;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.init();
    int choice, value;
    do
    {
        cout << "Choose your option" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. isFull" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty " << endl;
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
    return 0;
}
