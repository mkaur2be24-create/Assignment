#include <iostream>
using namespace std;
#define MAX 5
class Stack
{
    int arr[MAX];
    int top = -1;
    int minarr[MAX];
    int mintop = -1;
public:
    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == MAX - 1);
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++top] = x;
            if(mintop==-1 || minarr[mintop]>=x)
                minarr[++mintop]=x;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            if(arr[top]==minarr[mintop])
                mintop--;
            top--;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }
    void getMin()
    {
        
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << minarr[mintop] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, val;

    do
    {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Peek\n6. getMin\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is not Empty." << endl;
            break;
        case 4:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is not Full." << endl;
            break;
        case 5:
            s.peek();
            break;
        case 6:
            s.getMin();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
