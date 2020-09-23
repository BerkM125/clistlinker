#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->value = 1;
	Prepend(head, 0);
	Append(head, 2);
	PrintLinkedList(head);
	int returnArr[GetSize(head)];
	ToArray(head, returnArr);
	return 0;
}
