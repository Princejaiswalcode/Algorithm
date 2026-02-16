#include<stdio.h>
void printarray(int* arr,int n)
{   
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void insertionsort(int* arr,int start,int end)
{
    for(int i=start+1;i<end;i++)
    {
        int cur=arr[i];
        int prev=i-1;
        while(arr[prev]>cur)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=cur;      
    }
}
int main()
{
    int array[10]={12,34,2,4,434,223,53,23,234,34};
    int n=sizeof(array)/sizeof(array[0]);
    insertionsort(array,0,n);
    printarray(array,n);
    return 0;
}