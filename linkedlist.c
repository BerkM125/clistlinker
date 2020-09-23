#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void PrintLinkedList(struct ListNode *p) {
    struct ListNode *iterate;
    iterate = malloc(sizeof(struct ListNode));
    iterate = p;
    do {
        printf("%d ", iterate->value);
        iterate = iterate->next;
    } while (iterate != NULL) ;
    free(iterate);
    printf("\n");
}

void Append(struct ListNode *p, int value) {
    while (p->next != NULL) {
        p = p->next;
    }
    struct ListNode *addNode;
    addNode = malloc(sizeof(struct ListNode));
    addNode->value = value;
    addNode->next = NULL; 
    p->next = addNode;
}

void Prepend(struct ListNode *p, int value) {
    struct ListNode *addNode = NULL;
    addNode = malloc(sizeof(struct ListNode));
    addNode->value = p->value;
    addNode->next = p->next;
    p->value = value;
    p->next = addNode;
}

int GetSize(struct ListNode *p) {
    int count = 0;
    struct ListNode *iterate = p;
    iterate = malloc(sizeof(struct ListNode));
    while (iterate != NULL) {
        count += 1; 
        iterate = iterate->next;
    }
    free(iterate);
    return count;
}

void Remove(struct ListNode *p, int index) {
    if (index == 0) {
        PopFirst(p);
        return;
    }
    for(int i = 0; i <= index - 2; i++) {
        p = p->next;
    }
    if (p->next == NULL){
        free(p);
        return;
    }
    if(p != NULL) {
        p->next = p->next->next;
        return;
    }
}

void PopFirst(struct ListNode *p) {
    if (p == NULL)
        return;
    p->value = p->next->value;
    p->next = p->next->next;
}

void PopEnd(struct ListNode *p) {
    while (p->next->next != NULL) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

struct ListNode *ToLinkedList (int arr[], int sz) {
	int index = 0;
	struct ListNode *list = NULL;
	list = malloc(sizeof(struct ListNode));
	for(index = 0; index < sz; index++)
		Append(list, arr[index]);
	return (list);
}


int Get(struct ListNode *p, int location) {
	struct ListNode *list = p;
	int i;
    for(i = 0; i <= location; i++) {
		if(list->next != NULL)
			list = list->next;
		else 
			return (int)NULL;
	}
	return list->value;
}

void ToArray(struct ListNode *p, int *array) {
    for (int i = 0; i < GetSize(p); i++) {
        array[i] = p->value;
        p = p->next;
    }
}

int TraverseList(struct ListNode *head, int value)
{
	struct ListNode *n;
	int spot = 0;
	n = head;
	while (n != 0 && n->value != value) {
		n = n->next;
		spot++;
	}
	if (n == 0)
		return -1;
	return spot;
}

int Equal(struct ListNode *l1, struct ListNode *l2) {
    if (GetSize(l1) != GetSize(l2))
        return -1;
    for (int i = 0; i < GetSize(l1); i++) {
        if (Get(l1, i) != Get(l2, i)) 
            return -1;
    }
    return 1;
}
