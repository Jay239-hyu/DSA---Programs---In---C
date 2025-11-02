#include <stdio.h>
#include <stdlib.h>
struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct circularqueue * q)
{
    if((q->r + 1) % q -> size == q -> f) return 1;
    return 0; 
    
}

int isempty(struct circularqueue *q)
{
    if(q->r == q->f) return 1;
    return 0;
    
}

void enqueue(struct circularqueue *q , int val){
    if(isfull(q))
    {
        printf("Queue is full");
    }
    else
    {
      
        q->r =(q -> r + 1) % q -> size; //Circular Increment
        q->arr[q->r] = val;
    }
    
}
int dequeue(struct circularqueue *q){
    if(isempty(q))
    {
        printf("Queue is Empty\n");
        return -1;
       
    }
    else
    {
      
        q->f = (q -> f + 1) % q -> size; //Circular Increment
        return  q->arr[q->f];
        
    }
    
}
int main()
{
    struct circularqueue * q = (struct circularqueue*)malloc(sizeof(struct circularqueue));
    q -> size = 4;
    q -> f = 0;
    q -> r = 0;
    q -> arr = (int *)malloc(q->size* sizeof(int));

    enqueue(q , 12);
    enqueue(q , 13);
    enqueue(q , 14);
    
    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));

    enqueue(q , 15);
    enqueue(q , 16);
    enqueue(q , 17);

    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));

    // printf("%d" , isempty(q));
    // enqueue(q , 16);



return 0;
}