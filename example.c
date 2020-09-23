#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->value = 1;
	Prepend(head, 0);
	Append(head, 2);
	Append(head, 3);
	Append(head, 4);
	Append(head, 5);
	Append(head, 6);
	PrintLinkedList(head);
	Remove(head, 0);
	PrintLinkedList(head);
	return 0;
}
