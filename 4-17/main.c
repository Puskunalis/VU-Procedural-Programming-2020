// Vilius Puskunalis 5 grupe 17 uzduotis
#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.c"

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
    struct node *tail = NULL, *head = NULL;

    printf("Enter a series of numbers separated by spaces, ending it with 0:\n");
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

    printf("\nThe series with consecutive elements removed:\n");
    printElements(head);

    return 0;
}
