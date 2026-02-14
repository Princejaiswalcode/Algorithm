#include<stdio.h>
void printarray(int* array,int n)
{
    for(int i=0;i<=n;i++)
    {
        printf("%d\n",array[i]);
    }
}
int partition(int* arr,int st,int e)
{
    int j;
    int idx=st-1;
    int pivet=arr[e];//value of pivet,always a last element
    for(j=st;j<e;j++)
    {
        if(arr[j]<pivet)
        {
            idx++;
            int t=arr[idx];
            arr[idx]=arr[j];
            arr[j]=t;
        }
    }
    //till we traversed to the all values that are lesser PIVET Greater
    //WE JUST HV TO PUT THE PIVET VALUE AT END TO IDX++ POSTION 
    idx++;
    int t=arr[idx];
    arr[idx]=arr[e];
    arr[e]=t;
    return idx;
}
void quicksort(int* arr,int st,int e)
{
    if(st<e)
    {
        int pivIdx=partition(arr,st,e);
        quicksort(arr,st,pivIdx-1);//left
        quicksort(arr,pivIdx+1,e);//right
    }
}
int main()
{
    int array[10]={1,5,7,9,4,99,8,2,9,10};
    int n=sizeof(array)/sizeof(array[0]);
    quicksort(array,0,n-1);
    printarray(array,n-1);
    return 0;
}