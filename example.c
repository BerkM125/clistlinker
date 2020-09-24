#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->value = 0;
	Append(head, 1);
	Append(head, 2);
	printf("%d\n", Get(head, 1));
	return 0;
}
