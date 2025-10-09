struct Node
{
    int data;
    Node *next;
};
Node *reverseK(Node *head, int k)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr)
        head->next = reverseK(next, k);

    return prev;
}