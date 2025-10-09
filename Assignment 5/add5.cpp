struct PolyNode
{
    int coeff;
    int power;
    PolyNode *next;
};

PolyNode *addPoly(PolyNode *p1, PolyNode *p2)
{
    PolyNode *result = nullptr;
    PolyNode *tail = nullptr;

    while (p1 && p2)
    {
        PolyNode *temp = new PolyNode;
        temp->next = nullptr;

        if (p1->power == p2->power)
        {
            temp->coeff = p1->coeff + p2->coeff;
            temp->power = p1->power;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power)
        {
            temp->coeff = p1->coeff;
            temp->power = p1->power;
            p1 = p1->next;
        }
        else
        {
            temp->coeff = p2->coeff;
            temp->power = p2->power;
            p2 = p2->next;
        }

        if (!result)
            result = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    while (p1)
    {
        PolyNode *temp = new PolyNode{p1->coeff, p1->power, nullptr};
        tail->next = temp;
        tail = temp;
        p1 = p1->next;
    }

    while (p2)
    {
        PolyNode *temp = new PolyNode{p2->coeff, p2->power, nullptr};
        tail->next = temp;
        tail = temp;
        p2 = p2->next;
    }

    return result;
}