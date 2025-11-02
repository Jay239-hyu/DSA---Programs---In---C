#include <stdio.h>

void SelectionSort(int arr[] , int n)
{
    for(int i = 0; i < n -1  ; i++)
    {
        int min = i;
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;  
            }
   
        } 
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

}
int main()
{
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    SelectionSort(arr , n);

    for(int i = 0 ; i < n ; i++ )
    {
        printf("%d" , arr[i]);
    }


return 0;
}