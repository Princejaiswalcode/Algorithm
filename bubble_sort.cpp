#include<stdio.h>
int main()
{
    int array[5]={5,3,8,2,4};
    int n=sizeof(array)/sizeof(array[0]);
    int i,j;
    //bubble sort
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                //swap logic
                int t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d\n",array[i]);
        
    }
    printf("\n");

    return 0;
}

