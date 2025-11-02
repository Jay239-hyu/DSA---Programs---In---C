#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

void LLtraversal(struct Node *head){
    struct Node *ptr = head;
  do{
    printf("Element is %d\n" ,  ptr-> data);
    ptr = ptr -> next;   
}while(ptr != head); 
}   

struct Node  *InsertAtFirst(struct Node *head , int data ){
    
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while(p->next != head){
        p = p-> next;
    }

    ptr->data = data;
    ptr->next = head;
    p->next = ptr;

    head = ptr;

    return head;


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
    head->data = 4;
    head->next = second;
    // Link second and third Nodes
    second->data = 3;
    second->next = third;
    //Linkthird and fourth Nodes 
    third->data = 6;
    third->next = fourth;
    //Terminate the list at fourth node
    fourth -> data = 1;
    fourth->next = head;


head = InsertAtFirst(head , 45);
LLtraversal(head);

return 0;
}