#include<stdio.h>

#define N 4
#define W 8

int main()
{
    int weight[N] = {2,3,4,5};
    int profit[N] = {40,50,60,90};
    
    int dp[N+1][W+1];
    
    // Step 1: Initialize DP table
    for(int i=0;i<=N;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                dp[i][w]=0;
        }
    }
    
    // Step 2: Fill DP table
    for(int i=1;i<=N;i++)
    {
        for(int w=1;w<=W;w++)
        {
            if(weight[i-1] <= w)
            {
                int include = profit[i-1] + dp[i-1][w-weight[i-1]];
                int exclude = dp[i-1][w];
                
                if(include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    // Step 3: Print DP Table
    printf("\nDP Table:\n\n");
    for(int i=0;i<=N;i++)
    {
        for(int w=0;w<=W;w++)
        {
            printf("%3d ",dp[i][w]);
        }
        printf("\n");
    }
    
    // Step 4: Maximum Profit
    printf("\nMaximum Profit = %d\n",dp[N][W]);
    
    // Step 5: Find Selected Items
    printf("\nSelected Items:\n");
    int w = W;
    for(int i=N;i>0;i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            printf("Item %d (Weight=%d, Profit=%d)\n",i,weight[i-1],profit[i-1]);
            w = w - weight[i-1];
        }
    }
    
    return 0;
}