#include<stdio.h>
int main()
{
    int array[10]={1,25,7,64,3,9,7,6,56,8};
    int smallest_idx;
    int n=sizeof(array)/sizeof(array[0]);
    //selection sort
    for(int i=0;i<n-1;i++)
    {
        smallest_idx=i;//first element of the unsorted part
        for(int j=i+1;j<n;j++)
        {
            if(array[j]<array[smallest_idx])
            {
                smallest_idx=j;
            }
        }
        int t=array[smallest_idx];
        array[smallest_idx]=array[i];//smallest value from unsorted now on last value of new sorted array or first value of old unsorted array
        array[i]=t;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",array[i]);
    }
    return 0;
}