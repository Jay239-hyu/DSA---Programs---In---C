#include <stdio.h>

//[4,5,6,7,3,2]

void InsertionSort(int arr[] , int n)
{
    //Loop for Passes
    for(int i = 1; i <= n-1 ; i++)
    {
        int key = arr[i];
        int j = i-1;
        //Loop for each Pass
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;

        }
        arr[j+1] = key;
    }


  

}

int main()
{

    //Dry Run
    /*
    -1  0  1  2  3  4  5
        12|54 65 07 23 09 --> i = 1 , key=54 , j=0
        12|54 65 07 23 09 --> 1st Pass done (i = 1)!

        12 54|65 07 23 09 -->  i=2 , key=65 , j=1
        12 54|65 07 23 09 -->  2nd Pass done (i = 2)!

        12 54 65|07 23 09 -->  i=3 , key=07 , j=2
        12 54 65|65 23 09 -->  i=3 , key=07 , j=1
        12 54 54|65 23 09 -->  i=3 , key=07 , j=1
        12 12 54|65 23 09 -->  i=3 , key=07 , j=0
        07 12 54|65 23 09 -->  i=3 , key=07 , j=-1 --> 3rd Pass done(i=3)

        07 12 54 65|23 09 --> i=4 , key=23 , j=3
        
        |
        |
        |
        |

        Sorted - 07 09 12 23 54 65 --> After 5th Pass
    */
    int arr[] = {12,54,65,7,23,9};
    int n = 6;
    InsertionSort(arr , n); 

    
    for(int i = 0 ; i < n ; i++ )
    {
        printf("%d " , arr[i]);
    }



return 0;
}