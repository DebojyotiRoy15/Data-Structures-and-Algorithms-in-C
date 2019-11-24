//Time complexity for average case scenario is O(nlogn), for best case scenario is O(logn) and for worst case is O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int partition(int a[], int low, int high);
void QuickSort(int a[], int low, int high);

int c=0;

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int arr[100],i,n;
    printf("Size of array? \n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]: \n", i+1);
        scanf("%d", &arr[i]);
    }
    QuickSort(arr, 0, n-1);
    printf("The sorted array is : \n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n The number of comparisons is %d", c);
    return 0;
}

int partition(int a[], int low, int high)
{
    int index,i,j,pivot;
    //Generating random index for pivot
    index=rand()%(high-low+1)+low;
    swap(&a[index],&a[high]);
    pivot=a[high];
    i=low-1;
    for(j=low;j<high;j++)
    {
        c++;
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return (i+1);
}

void QuickSort(int a[], int low, int high)
{
    int loc;
    if(low<high)
    {
        loc=partition(a,low,high);
        QuickSort(a,low,loc-1);
        QuickSort(a,loc+1,high);
    }
}
