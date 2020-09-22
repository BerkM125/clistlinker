#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Creating a node
struct ListNode {
    int value;
    struct ListNode *next;
};

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
    for(int i = 0; i <= index - 1; i++) {
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
    free(p->next);
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
