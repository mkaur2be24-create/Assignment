struct Node
{
    int data;
    Node *next;
};
void removeLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
    }
}