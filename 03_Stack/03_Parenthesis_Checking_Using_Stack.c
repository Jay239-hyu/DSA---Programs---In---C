#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

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

int pop(struct stack *ptr , char expected)
{
    if(isempty(ptr)) return 0;

    char topChar = ptr->arr[ptr->top];
    if ((expected == ')' && topChar == '(') ||
             (expected == ']' && topChar == '[') ||
             (expected == '}' && topChar == '{'))
    {
        ptr->top--;
        return 1; //Sucessfully poped the value
    }
    else
    {
        return 0; //Mismatch → unbalanced
    }
}

int parenthesisMatch(char equation[]){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

        for (int i = 0; equation[i] != '\0'; i++)
    {
        if (equation[i] == '(' || equation[i] == '[' || equation[i] == '{')
        {
            push(sp, equation[i]);
        }
        else if (equation[i] == ')' || equation[i] == ']' || equation[i] == '}')
        {
            if (!(pop(sp , equation[i]))){
                return 0;//Mismatch    
            }  
        }
    }
    
    // If stack is empty → all matched
    return isempty(sp);
}

int main()
{
    char equation[100];
    // Read Equation
    printf("Enter the equation:  ");
    fgets(equation, sizeof(equation), stdin);

    // remove newline if present
    for (int i = 0; equation[i]; i++) {
        if (equation[i] == '\n'){
            equation[i] = '\0';
            break;
        }
    }


    printf("You entered: %s\n", equation);

    if (parenthesisMatch(equation)){
        printf("The Parenthesis is matching");
    }
    else{
        printf("The Parenthesis is not matching");
    }

    return 0;
}