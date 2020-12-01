// Vilius Puskunalis 5 grupe 17 uzduotis
#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.c"

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

void removeConsecutiveElements(struct node* head)
{
    struct node *currentNode = head;

    while (currentNode != NULL && currentNode->next != NULL)
    {
        if (currentNode->data == currentNode->next->data)
        {
            removeNode(currentNode->next);
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
}

int main()
{
    int data;
    struct node *tail = NULL, *head;

    scanf("%d", &data);

    while (data != 0)
    {
        if (tail != NULL)
        {
            tail = insertAfter(tail, data);
        }
        else
        {
            tail = createNode(data);
            head = tail;
        }

        scanf("%d", &data);
    }

    removeConsecutiveElements(head);

    printElements(head);

    return 0;
}
