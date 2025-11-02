#include <stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int usage_size;
    int *ptr;
};

void createArray(struct myArray*a , int tSize ,int uSize ){
a->total_size = tSize;
a->usage_size = uSize;
a->ptr = (int *) malloc(tSize * sizeof(int));
}

void show(struct myArray *a){

    for(int i = 0; i < a->usage_size ; i++ )
    {
        printf("%d\n", (a->ptr)[i]); 
    }
    
}

void setval(struct myArray *a){
    int n;
    for(int i = 0; i < a->usage_size ; i++ )
    {

        printf("Enter element %d" , i);
        scanf("%d" , &n);
        (a->ptr)[i] = n;   //or *(a->ptr + i) = n;

    }
    
}
int main()
{
struct myArray marks;
createArray(&marks , 10 , 2 );
printf("We are running setval now\n");
setval(&marks);
printf("We are running show now\n");
show(&marks);

return 0;
}