#include<stdio.h>
#include <stdbool.h>

int main()
{
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i,j;

    for(i=0;i<n-1;i++)
    {
        bool is_swap = false;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                is_swap=true;
            }
        }
        if(is_swap==false)
        {
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}