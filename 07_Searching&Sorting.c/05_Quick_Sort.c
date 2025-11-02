#include <stdio.h>


int partition(int arr[] , int low , int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    do{
        while(arr[i] <= pivot)
        {
            i++;
        }

        while(arr[j] > pivot)
        {
            j--;
        }

        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while(i < j);


    //Swap arr[low] and arr[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void QuickSort(int arr[] , int low , int high)
{
    int PartitionIndex; //Index of Pivot after partition
    if(low<high){
    PartitionIndex = partition(arr , low , high);
    QuickSort(arr , low , PartitionIndex-1); //Sort left subarray
    QuickSort(arr , PartitionIndex+1 , high); //Sort Right subarray
    }


}
int main()
{

    int arr[] = {3,5,2,13,12};
    int n = 5;
    QuickSort(arr , 0 , n-1);

    for(int i = 0 ; i < n ; i++ )
    {
        printf("%d " , arr[i]);
    }


return 0;
}