struct ListNode {    
    int value;
    struct ListNode * next;
};

void PrintLinkedList(struct ListNode *p);
void Prepend(struct ListNode *p, int value);
void Append(struct ListNode *p, int value);
void Remove(struct ListNode *p, int location);
void Get(struct ListNode *p, int location);
