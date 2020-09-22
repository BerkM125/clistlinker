struct node {    
	int value;
    struct node * next;
};

void PrintLinkedList(struct node *p);
void Prepend(struct node *p, int value);
void Append(struct node *p, int value);
void Remove(struct node *p, int location);
