#include<stdio.h>
// int fib(int n)
// {
//     int arr[n];
//     if(n<0){
//         printf("error!!\n");
//         return -1;
//     }
//     if(n==1) return 1;
//     if(n==0) return 0;
//     int sum=fib(n-1)+fib(n-2);
//     return sum;
// }
int fib(int n,int* arr)
{
    if(n==0 || n==1) return n;
    if(arr[n]==-1) return arr[n];
    int sum=fib(n-1,arr)+fib(n-2,arr);
    return arr[n]=sum;
}

int main()
{
    int number;
    printf("Fibonaic series using dynamic programming---top down approch\n\n");
    printf("enter a number :");
    scanf("%d",&number);
    while(getchar()!='\n');
    int Array[number];
    printf("%d\n",fib(number,Array));
    return 0;
}