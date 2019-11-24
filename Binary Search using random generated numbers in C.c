#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void binary(int arr[], int n);

int main()
{
    int rand1[100], aux[100],n,j,i,temp;
    printf("Size of array? \n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        aux[i]=0;
    }
    i=0;
    while(i<n)
    {
        temp=rand()%n;
        if(aux[temp]==0)
        {
            rand1[i++]=temp;
            aux[temp]++;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ", rand1[i]);
    binary(rand1, n);
    return 0;
}

void binary(int arr[], int n)
{
    int low, high, i,j,temp,mid,key,c=0,flag=0;
    printf("Enter value to search? \n");
    scanf("%d", &key);
    low=0;
    high=n-1;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    while(low<high)
    {
        c++;
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
            printf("Element found at %d position. \n", mid+1);
            flag=1;
            break;
        }
        else if(key<arr[mid])
        {
            high=mid-1;
        }
        else if(key>arr[mid])
        {
            low=mid+1;
        }

    }

    if(flag==0)
    {
        printf("Element not present in array. \n");
    }
}
