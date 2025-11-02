#include <stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node * DeleteAtFirst(struct Node *head ){
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

void DeleteAtIndex(struct Node *head , int index){
    struct Node *p = head;
    int i=0;
    while(i != index - 1){
       p =  p -> next;
       i++;
    }
struct Node *q;

q = p -> next;
p -> next = q -> next;
free(q);
}

void DeleteAtEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head -> next;
    int i=0;
    while(q -> next != NULL){
       p =  p -> next;
       q =  q -> next;
       i++;
    }
p -> next = NULL;
free(q);
}

struct Node * DeleteByValue(struct Node *head , int val){

    if (head->data == val) {
        struct Node *ptr = head;
        head = head -> next;
        free(ptr);
        return head;   
}
    struct Node *p = head;
    struct Node *q = head -> next;
    while(q -> data != val){
       p =  p -> next;
       q = q -> next;
    }
p -> next = q -> next;
free(q);
return head;
}   



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
     
    // printf("Linked List Before deletion:\n");
    // LLTraversal(head);

    // printf("\nLinked List after deletion of first Node:\n");
    // head = DeleteAtFirst(head);
    // LLTraversal(head);

    // printf("Linked List Before deletion:\n");
    // LLTraversal(head);

    // printf("\nLinked List after deletion of first Node:\n");
    // DeleteAtIndex(head , 2);
    // LLTraversal(head);

    // printf("Linked List Before deletion:\n");
    // LLTraversal(head);

    // printf("\nLinked List after deletion of first Node:\n");
    // DeleteAtEnd(head);
    // LLTraversal(head);

    printf("Linked List Before deletion:\n");
    LLTraversal(head);

    printf("\nLinked List after deletion of first Node:\n");
    head = DeleteByValue(head , 7 );
    LLTraversal(head);


}