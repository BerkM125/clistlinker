#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// print the linked list value
void PrintLinkedList(struct ListNode *p) {
    struct ListNode *iterate;
    iterate = malloc(sizeof(struct ListNode));
    iterate = p ;
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
    while (p != NULL) {
        count += 1; 
        p = p->next;
    }
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

int Get(struct ListNode *p, int location) {
	struct ListNode *list = p;
	int i;
    for(i = 0; i <= location; i++) {
		if(list->next != NULL)
			list = list->next;
		else 
			return -1;
	}
	return list->value;
}

void ToArray(struct ListNode *p, int *array) {
    for (int i = 0; i < GetSize(p); i++) {
        array[i] = p->value;
        p = p->next;
    }
}
