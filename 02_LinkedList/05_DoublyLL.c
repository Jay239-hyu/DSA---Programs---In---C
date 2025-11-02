#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void LLTraversal(struct Node *ptr)
{
    do{
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != NULL);
}

void ReverseLLTraversal(struct Node *ptr)
{

    struct Node *p= ptr;
    while(p->next != NULL){
        p = p->next;
    }
    do{
        printf("Element:%d\n", p->data);
        p = p->prev;
    }while (p != NULL);
}



int main(){

    
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
    head->prev = NULL;
    // Link second and third Nodes
    second->data = 11;
    second->next = third;
    second->prev = head;
    //Linkthird and fourth Nodes 
    third->data = 5;
    third->next = fourth;
    third->prev = second;
    //Terminate the list at fourth node
    fourth -> data = 8;
    fourth->next = NULL;
    fourth->prev = third;

    ReverseLLTraversal(head);





return 0;
}