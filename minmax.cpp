#include<stdio.h>
void minmax(int*arr,int low,int high,int* max,int* min)
{
    int mid;
    //stopage conditions
    if(low==high)
    {
        *min=*max=arr[low];//can be min=max=arr[max],one in the same thing  
    }
    else if(low==high-1)
    {
        if(arr[low]<arr[high])
        {
            *min=arr[low];
            *max=arr[high];
        }
        else{
            *min=arr[high];
            *max=arr[low];
        }
    }
    else{
        int max1,min1,min2,max2;
        mid=low+(high-low)/2;
        minmax(arr,low,mid,&max1,&min1);//left part
        minmax(arr,mid+1,high,&max2,&min2);//right part
        if(max1>max2)
        {
            *max=max1;
        }
        else{
            *max=max2;
        }
        if(min1<min2)
        {
            *min=min1;
        }
        else{
            *min=min2;
        }
    }
}
int main()
{
    int array[10]={56,5,6,53,2,6,7,445,8784,890};
    int min,max;
    int n=sizeof(array)/sizeof(array[0]);
    minmax(array,0,n-1,&max,&min);
    printf("maximum value is %d\n",max);
    printf("Minimum value is %d\n",min);
    return 0;
}