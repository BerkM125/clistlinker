#ifndef clistlinker
#define clistlinker

struct ListNode {    
    int value;
    struct ListNode * next; // = malloc();
};

void PrintLinkedList(struct ListNode *p);
void Prepend(struct ListNode *p, int value);
void Append(struct ListNode *p, int value);
void Remove(struct ListNode *p, int location);
int Get(struct ListNode *p, int location);

#endif
