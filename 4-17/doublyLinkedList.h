// Vilius Puskunalis 5 grupe 17 uzduotis
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct node
{
    int data;
    struct node *prev, *next;
} node;

typedef struct doublyLinkedList
{
    struct node *head, *tail;
} doublyLinkedList;

node* createNode(int data);
void removeNode(node* node);

doublyLinkedList* createList();
void destroyList(doublyLinkedList* list);

void push(doublyLinkedList* list, int data);
void unshift(doublyLinkedList* list, int data);

void printElementsForward(doublyLinkedList* list);
void printElementsBackward(doublyLinkedList* list);

#endif
