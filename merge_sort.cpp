#include<stdio.h>

void merge(int* a,int st,int m,int e)
{
    int i,j,k=0;
    int R[e-st+1];
    i=st;
    j=m+1;
    while(i<=m && j<=e)
    {
        if(a[i]<a[j])
        {
            R[k]=a[i];
            i++;
            k++;
        }
        else{
            R[k]=a[j];
            j++;
            k++;
        }
    }
    while(j<=e)
    {
        R[k]=a[j];
        k++;
        j++;
    }
    while(i<=m)
    {
        R[k]=a[i];
        i++;
        k++;
    }

    //copy to actual array r->a
    for(i=st;i<=e;i++)
    {
        a[i]=R[i-st];
    }
}
void printarray(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void mergesort(int* arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

int main()
{
    int array[10]={1,4,2,5,23,74,8,5,8,9};
    int n=sizeof(array)/sizeof(array[0]);
    mergesort(array,0,n-1);
    printarray(array,n);
}
