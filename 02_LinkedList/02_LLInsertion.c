#include <stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};


struct Node * insertAtFirst(struct Node *head ,int data){

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}
struct Node * insertAtEnd(struct Node *head ,int data){

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head;

    while(p-> next != NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    return head; 
}

struct Node * insertAfterNode(struct Node *head ,struct Node *prevNode , int data){

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    return head; 
}

struct Node * insertAtIndex(struct Node *head ,int data , int index){

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    
    int i = 0;
    while(i != index-1){
        
        p = p -> next;
        i++;
    }   
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
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
     
    printf("Linked List Before insertion\n");
    LLTraversal(head);
    
    // head = insertAtFirst(head ,  56);
    // printf("Linked List After insertion\n");
    // LLTraversal(head);

    // head = insertAtIndex(head , 56 , 1);
    // printf("Linked List After insertion\n");
    // LLTraversal(head);

    // head = insertAtEnd(head , 56);
    // printf("\nLinked List After insertion\n");
    // LLTraversal(head);

    head = insertAfterNode(head , second , 54);
    printf("\nLinked List After insertion\n");
    LLTraversal(head);


return 0;
}