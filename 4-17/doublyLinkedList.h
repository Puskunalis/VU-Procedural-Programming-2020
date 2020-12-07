// Vilius Puskunalis 5 grupe 17 uzduotis
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct node
{
    int data;
    struct node *prev, *next;
};

struct node* createNode(int data);

struct node* insertAfter(struct node* currentNode, int data);

void removeNode(struct node* node);

void printElements(struct node* head);

#endif
