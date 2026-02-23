#include<stdio.h>
int fib(int n)
{
    int i;
    int Array[n];
    Array[0]=0;
    Array[1]=1;
    for(i=2;i<=n;i++){
        Array[i]=Array[i-1]+Array[i-2];
    }
    return Array[n];
}

int main()
{
    int number;
    printf("Fibonci series using bottom to top approch of dynamic programming \n");
    printf("enter a number :");
    scanf("%d",&number);
    while(getchar()!='\n');
    printf("Fibonic series result : %d\n",fib(number));

    return 0;
}
