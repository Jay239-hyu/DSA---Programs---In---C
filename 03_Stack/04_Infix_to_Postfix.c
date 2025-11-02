#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int isempty(struct stack *ptr)
{

    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isfull(struct stack *ptr)
{

    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val)
{
    // Check if stack is full
    if (isfull(ptr))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    //Check if stack is empty
    if(isempty(ptr)){ 
        printf("Stack Underflow!\n");
        return -1; // or some sentinel value
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' || ch == '/' )  return 3;
        
    else if(ch == '+' || ch == '-')  return 2;

    else return 0;
}

int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' )
     return 1;
    else
     return 0;
}



char * infixtopostfix(char infix[]){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp -> arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; //Track infix traversal
    int j = 0; //Track postfix traversal
    while(infix[i] != '\0')
    {
        if(!(isOperator(infix[i])))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp , infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!(isempty(sp)))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;


}



int main()
{
    char infix[100];
    // Read Equation
    printf("Enter the equation:  ");
    fgets(infix, sizeof(infix), stdin);

    // remove newline if present
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '\n'){
            infix[i] = '\0';
            break;
        }
    }

    printf("Postfix is %s" , infixtopostfix(infix));



    return 0;
}