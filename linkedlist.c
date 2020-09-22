struct node {    
	int value;
    struct node * next;
};

void PrintLinkedList(struct node *p) {
	int c = 0;
    while (p != NULL) {
        printf("#%d %d\n", c, p->value);
        p = p->next;
		c++;
    }
}
void Append(struct node *p, int value) {
    while (p->next != NULL) {
        p = p->next;
    }
    struct node *addNode = NULL;
    addNode = malloc(sizeof(struct node));
    addNode->value = value;
    p->next = addNode;  
}

void Prepend(struct node *p, int value) {
    struct node *addNode = NULL;
    addNode = malloc(sizeof(struct node));
    addNode->value = p->value;
    addNode->next = p->next;
    p->value = value;
    p->next = addNode;
}

void Remove(struct node *p, int location) {
	struct node *list = p;
    for(int i = 0; i <= location; i++) {
        if(i == location-1) {
			if(list != NULL) 
				list->next = list->next->next;
		}
		list = list->next;
    }

}
