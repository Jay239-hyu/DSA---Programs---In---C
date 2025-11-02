#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isempty(struct Node * top){
    if (top == NULL){
        return 1;
    }
    return 0;
}
int isfull(struct Node * top){
    struct Node *p = (struct Node*)malloc (sizeof(struct Node));
    if (p == NULL){
        return 1;
    }
    free(p);
    return 0;
}

struct Node* push(struct Node *top , int val){
    if(!isfull(top)){
    struct Node *Newnode;
    Newnode = (struct Node *) malloc(sizeof(struct Node));
    Newnode->data = val;
    Newnode->next = top;
    top = Newnode;
    return top;
    }
    printf("Stack is Overflow!");
    return top;
}

struct Node * pop(struct Node *top , int *popedvalue){

    if(!isempty(top)){

    *popedvalue = top->data;
    struct Node *ptr = top;
    top = top->next;
    free(ptr);
    return top;   
    }
    printf("Stack is Underflow!\n");
    *popedvalue = -1;
    return top;    
}

int peek(struct Node *top , int pos){
    struct Node *ptr = top;
    for(int i = 0; i<pos-1 && ptr != NULL ; i++){
        ptr = ptr->next;
    }
    if(ptr) return ptr->data;
    else return -1;
}

int stack_top(struct Node *top){
    return top->data;
}

int stack_bottom(struct Node *top){
    struct Node *ptr = top;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    return ptr->data;
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
    struct Node *top = NULL;  // stack initially empty

    top = push(top, 7);
    top = push(top, 11);
    top = push(top, 5);
    top = push(top, 8);
    
    // int val;
    // top = pop(top , &val);
    // printf("Poped value is %d\n",val);
    // top = pop(top , &val);
    // printf("Poped value is %d\n",val);

    // LLTraversal(top);

    printf("Bottom:%d\n" , stack_bottom(top));
    printf("Top:%d" , stack_top(top)) ;




return 0;
}