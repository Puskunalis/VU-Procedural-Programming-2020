// Vilius Puskunalis 5 grupe 17 uzduotis
#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

struct node* createNode(int data)
{
    struct node* head = (struct node*) malloc(sizeof(struct node));

    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

struct node* insertAfter(struct node* currentNode, int data)
{
    struct node* newNode = createNode(data);

    if (currentNode->next != NULL)
    {
        newNode->next = currentNode->next;
        newNode->next->prev = newNode;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;

    return newNode;
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

void printElements(struct node* head)
{
    struct node *currentNode = head;

    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}
