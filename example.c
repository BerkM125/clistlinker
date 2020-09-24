#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->value = 1;
	Prepend(head, 0);
	int param [] = {2, 3, 4, 5, 6, 7, 8};
	MultiAppend(head, param);
	// Reverse(&head);
	PrintLinkedList(head);
	// Append(head, 2);
	// Append(head, 3);
	// Append(head, 4);
	// Append(head, 5);
	// Append(head, 6);
	return 0;
}
