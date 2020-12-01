// Vilius Puskunalis 5 grupe 17 uzduotis

struct node
{
    int data;
    struct node *prev, *next;
};

struct node* createNode(int data);
struct node* insertAfter(struct node* currentNode, int data);
void removeNode(struct node* node);
