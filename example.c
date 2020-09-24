#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->value = 0;
	Append(head, 1);
	Append(head, 2);
	Append(head, 3);
	printf("%d\n", Get(head, 1));
	int array[GetSize(head)];
	// printf("%d\n", GetSize(head));
	// ToArray(head, array);
	// for (int i = 0; i < GetSize(head); i++) {
	// 	printf("%d ", array[i]);
	// }
	return 0;
}
