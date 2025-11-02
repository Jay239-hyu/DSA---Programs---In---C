#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr){

    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isfull(struct stack *ptr){

    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}   

void push(struct stack *ptr,int val ){
    //Check if stack is full
    if(isfull(ptr)){
        printf("Stack is Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val; 
    }
}

int pop(struct stack *ptr){
    //Check if stack is empty
    if(isempty(ptr)){
        printf("Stack Underflow!\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr , int position){
    if(ptr->arr[ptr->top - position + 1] < 0){
        printf("Invalid Position!");
        return -1;
    }
    
    return ptr->arr[ptr->top - position + 1];
}

int top(struct stack *ptr){
    return ptr->arr[ptr->top];
}
int bottom(struct stack *ptr){
    return ptr->arr[0];
}



int main()
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));

    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created sucessfully.\n");


    push(sp , 2);
    push(sp , 3);
    push(sp , 4);
    printf("The top most value of this stack is %d\n",top(sp));
    printf("The bottom most value of this stack is %d\n",bottom(sp));









return 0;
}