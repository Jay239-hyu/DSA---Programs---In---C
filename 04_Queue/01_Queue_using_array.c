#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue * q)
{
    if(q->r == q -> size-1) return 1;
    return 0;
    
}
int isempty(struct queue *q)
{
    if(q->r == q->f) return 1;
    return 0;
    
}
void enqueue(struct queue *q , int val){
    if(isfull(q))
    {
        printf("Queue is full");
       
    }
    else
    {
      
        q->r++;
        q->arr[q->r] = val;
    }
    
}
int dequeue(struct queue *q){
    if(isempty(q))
    {
        printf("Queue is Empty\n");
        return -1;
       
    }
    else
    {
      
        q->f++;
        return  q->arr[q->f];
        
    }   
    
}
int main()
{
    struct queue * q = (struct queue*)malloc(sizeof(struct queue));
    q -> size = 10;
    q -> f = -1;
    q -> r = -1;
    q -> arr = (int *)malloc(q->size* sizeof(int));

    enqueue(q , 12);
    enqueue(q , 13);
    enqueue(q , 14);
    enqueue(q , 15);
    
    // printf("%d" , isempty(q));
    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));
    printf("%d\n" , dequeue(q));

    



return 0;
}