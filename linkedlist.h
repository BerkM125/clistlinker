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
void ToArray(struct ListNode *p, int *array);
int GetSize(struct ListNode *p);
void PopFirst(struct ListNode *p);
void PopEnd(struct ListNode *p);
void Remove(struct ListNode *p, int index);

#endif
