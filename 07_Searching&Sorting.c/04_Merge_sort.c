#include <stdio.h>
#include <stdlib.h>


void merge(int arr[] , int l , int m , int r)
{
    int n1 = m - l + 1; //No. of Ele. in left Half
    int n2 = r - m;//No. of Ele, in right half

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for(int i = 0 ; i < n1 ; i++) L[i] = arr[l + i];
    for(int j = 0 ; j < n2 ; j++) R[j] = arr[m + 1 + j];
    
    int i = 0 , j = 0 , k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergesort(int arr[] , int l , int r)
{
    if (l >= r) return;
    int m = l + (r - l)/2;
    mergesort(arr , l , m);
    mergesort(arr , m+1 , r);
    merge(arr , l , m , r);
}

int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    mergesort(a, 0, n - 1);

    printf("Sorted:   ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
