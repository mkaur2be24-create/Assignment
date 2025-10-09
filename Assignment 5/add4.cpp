struct Node
{
    int data;
    Node *next;
};
Node *rotateLeft(Node *head, int k)
{
    if (!head || k == 0)
        return head;

    Node *temp = head;
    int len = 1;
    while (temp->next)
    {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if (k == 0)
        return head;

    temp->next = head; 
    Node *newEnd = head;
    for (int i = 1; i < k; i++)
        newEnd = newEnd->next;

    Node *newHead = newEnd->next;
    newEnd->next = nullptr;

    return newHead;
}