#include <stdio.h>

#define N 4
#define W 8

int weight[N] = {2,3,4,5};
int profit[N] = {40,50,60,90};

int dp[N+1][W+1];

// Recursive function (Recurrence Relation)
int knapsack(int n, int w)
{
    if(n == 0 || w == 0)
        return 0;

    if(dp[n][w] != -1)
        return dp[n][w];

    if(weight[n-1] > w)
        dp[n][w] = knapsack(n-1, w);
    else
    {
        int include = profit[n-1] + knapsack(n-1, w - weight[n-1]);
        int exclude = knapsack(n-1, w);

        dp[n][w] = (include > exclude) ? include : exclude;
    }

    return dp[n][w];
}

int main()
{
    // Initialize DP table
    for(int i=0;i<=N;i++)
        for(int j=0;j<=W;j++)
            dp[i][j] = -1;

    int maxProfit = knapsack(N, W);

    // Print DP Table
    printf("\nDP Table:\n\n");
    printf("n/w  ");
    for(int w=0; w<=W; w++)
        printf("%4d", w);
    printf("\n");

    for(int i=0; i<=N; i++)
    {
        printf("%2d   ", i);
        for(int w=0; w<=W; w++)
        {
            if(dp[i][w] == -1)
                printf("%4d", 0);
            else
                printf("%4d", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", maxProfit);

    // Find Selected Items
    printf("\nSelected Items:\n");
    int w = W;

    for(int i = N; i > 0; i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            printf("Item %d (Weight=%d, Profit=%d)\n",
                   i, weight[i-1], profit[i-1]);
            w = w - weight[i-1];
        }
    }

    return 0;
}