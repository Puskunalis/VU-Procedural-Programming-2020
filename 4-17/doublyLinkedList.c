// Vilius Puskunalis 5 grupe 17 uzduotis
#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

node* createNode(int data)
{
    node *head = (node*) malloc(sizeof(node));

    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

void removeNode(struct node* node)
{
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    else
    {
        node->next->prev = NULL;
    }

    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }
    else
    {
        node->prev->next == NULL;
    }

    free(node);
}

doublyLinkedList* createList()
{
    doublyLinkedList *list = (doublyLinkedList*) malloc(sizeof(doublyLinkedList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void destroyList(doublyLinkedList* list)
{
    node *currentNode = list->head, *nextNode;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(list);
}

void push(doublyLinkedList* list, int data)
{
    node *newNode = createNode(data);

    if (list->tail != NULL)
    {
        newNode->prev = list->tail;
        newNode->prev->next = newNode;
    }
    else
    {
        list->head = newNode;
    }

    list->tail = newNode;
}

void unshift(doublyLinkedList* list, int data)
{
    node *newNode = createNode(data);

    if (list->head != NULL)
    {
        newNode->next = list->head;
        newNode->next->prev = newNode;
    }
    else
    {
        list->tail = newNode;
    }

    list->head = newNode;
}

void printElementsForward(doublyLinkedList* list)
{
    node *currentNode = list->head;

    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

void printElementsBackward(doublyLinkedList* list)
{
    node *currentNode = list->tail;

    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->prev;
    }

    printf("\n");
}
