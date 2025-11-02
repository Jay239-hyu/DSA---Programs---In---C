#include <stdio.h>

int Linearsearch(int arr[] , int size , int element ){
//Code for LinearSearch
for(int i = 0; i<size; i++){

    if (arr[i] == element){
        return i;
    }
}
    return -1;
}

int Binarysearch(int arr[] , int size , int element){
    int low =0 , mid ,high = size-1;
    //Keep searching until low <=> mid
    while(low<=high) {
    mid = (low + high)/2;
    if(arr[mid] == element){
        return mid;
    }
    if(arr[mid] < element){
        low = mid + 1;                         
    }
    else{
        high = mid - 1;
    }
}   
    return -1;
}


int main()
{
    //Unsorted array for Linearsearch
    // int arr[] = {7,8,12,27,88,90};
    // int size = sizeof(arr)/sizeof(int);

    //Sorted array for Linearsearch
    int arr[] = {7,8,12,27,88,90};
    int size = sizeof(arr)/sizeof(int);
    int element = 27;    
    int searchIndex = Binarysearch(arr ,size , 27);
    printf("The element %d was found at index %d \n", element , searchIndex);
    return 0;
}

 
