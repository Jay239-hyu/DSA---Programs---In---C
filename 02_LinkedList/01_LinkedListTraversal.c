#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LLTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second Nodes
    head->data = 7;
    head->next = second;
    // Link second and third Nodes
    second->data = 11;
    second->next = third;
    //Linkthird and fourth Nodes 
    third->data = 5;
    third->next = fourth;
    //Terminate the list at fourth node
    fourth -> data = 8;
    fourth->next = NULL;

    



    LLTraversal(head);

    return 0;
}