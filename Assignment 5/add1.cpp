#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *getIntersectionNode(Node *headA, Node *headB)
{
    if (!headA || !headB)
        return nullptr;

    Node *p1 = headA;
    Node *p2 = headB;

    while (p1 != p2)
    {
        p1 = (p1 == nullptr) ? headB : p1->next;
        p2 = (p2 == nullptr) ? headA : p2->next;
    }
    return p1;
}