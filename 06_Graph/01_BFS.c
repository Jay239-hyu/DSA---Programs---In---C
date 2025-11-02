#include <stdio.h>
#include<stdlib.h>


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
        return q->arr[q->f];
        
    }   
    
}


int main()
{

    //Initializing Queue(Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size* sizeof(int));

    //BFS Implimentation
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d" , i);
    visited[i] = 1;

    enqueue(&q , i);

    while(!isempty(&q))
    {
     int node = dequeue(&q);

     for(int j=0 ; j < 7 ; j++)
     {
        if(a[node][j] ==1 && visited[j] == 0)
        {
            printf("%d" , j);
            visited[j] = 1;
            enqueue(&q , j);
        }
     }
    }
    




return 0;
}