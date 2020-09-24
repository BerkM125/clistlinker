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

void MultiAppend(struct ListNode *p, int *values, int size) {
    for (int i = 0; i < size - 1; i++) {
        Append(p, values[i]);
    }
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

struct ListNode *ToLinkedList (int *arr, int sz) {
	int index = 0;
	struct ListNode *list = NULL;
	list = malloc(sizeof(struct ListNode));
	for(index = 0; index < sz - 1; index++)
		Append(list, arr[index]);
	return list;
}

int Get(struct ListNode *p, int location) {
    for(int i = 1; i <= location; i++) {
		if(p->next != NULL)
			p = p->next;
		else 
			return -1;
	}
	return p->value;
}

void ToArray(struct ListNode *p, int *array) {
    int size = GetSize(p);
    for (int i = 0; i < size; i++) {
        array[i] = p->value;
        p = p->next;
    }
}

int FindNumber(struct ListNode *head, int value) {
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
    for (int i = 0; i < GetSize(l1); i++)
        if (Get(l1, i) != Get(l2, i)) 
            return -1;
    return 1;
}

void Reverse(struct ListNode **head) {
    struct ListNode* prev = NULL; // = malloc(sizeof(struct ListNode));
    struct ListNode* current = *head;
    struct ListNode* next = NULL; // = malloc(sizeof(struct ListNode));
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void RemoveCopies(struct ListNode *p) {
    struct ListNode *ptr1, *ptr2, *dup;
    ptr1 = p;
    while (ptr1 != NULL && ptr1 ->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->value == ptr2->next->value) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

struct ListNode *SimilarElements(struct ListNode *head1, struct ListNode *head2) {
    struct ListNode* similar = malloc(sizeof(struct ListNode));
    struct ListNode* iterate = NULL;
    struct ListNode* iterate2 = NULL;
    struct ListNode* reference = NULL;
    if (GetSize(head1) > GetSize(head2) || GetSize(head1) == GetSize(head2)) {
        iterate = head1;
        reference = head2;
        iterate2 = head2;
    } else {
        iterate = head2;
        reference = head1;
        iterate2 = head1;
    }
    while (iterate != NULL) {
        iterate2 = reference;
        while (iterate2 != NULL) {
            if (iterate->value == iterate2->value) {
                Append(similar, iterate->value);
            }
            iterate2 = iterate2->next;
        }
        iterate = iterate->next;
    }
    RemoveCopies(similar);
    free(iterate);
    free(iterate2);
    free(reference);
    return similar;
}
