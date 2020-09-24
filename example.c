#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->value = 0;
	struct ListNode *head1;
	head1 = malloc(sizeof(struct ListNode));
	head1->value = 0;
	int array[] = {1, 2, 3, 4, 12};
	int array1[] = {1, 9, 10, 11, 12};
	MultiAppend(head, array, (sizeof array / sizeof *array));
	MultiAppend(head1, array1, (sizeof array1 / sizeof *array1));
	struct ListNode *similar;
	similar = SimilarElements(head, head1);
	PrintLinkedList(similar);
	return 0;
}
