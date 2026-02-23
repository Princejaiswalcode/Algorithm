#include<stdio.h>
int deadline[5]={2,1,2,1,3};
int profit[5]={100,50,10,20,30};
int transaction_id[5]={1,2,3,4,5};
int max_deadline=-1;
int n=sizeof(profit)/sizeof(profit[0]);
int schedule[5];

int total_profit=0;

void maxdeadline()
{
    max_deadline=deadline[0];
    for(int i=1;i<n;i++)
    {
        if(max_deadline<deadline[i])
        {
            max_deadline=deadline[i];
        }
    }
}

void bubble()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(profit[j]<profit[j+1])
            {
                int t=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=t;

                t=deadline[j];
                deadline[j]=deadline[j+1];
                deadline[j+1]=t;

                t=transaction_id[j];
                transaction_id[j]=transaction_id[j+1];
                transaction_id[j+1]=t;
            }
        }
    }
}

void printsq()
{
    printf("-------------------------------------------\n");
    printf("| Transaction Id |    Profit  |\t Deadline |\n");
    printf("-------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("|\tT%d     \t |\t%d    |    %d\t  |\n",transaction_id[i],profit[i],deadline[i]);
    }
    printf("-------------------------------------------\n\n\n");

}

void job_sq()
{
    maxdeadline();
    for(int i=0;i<n;i++)
    {
        for(int d=deadline[i]-1;d>=0;d--)
        {
            if(schedule[d]==-1)
            {
                schedule[d]=transaction_id[i];
                total_profit+=profit[i];
                break;
            }
        }
    }
    printf("total profit: %d\n",total_profit);


}

int main()
{   
    for(int i=0;i<n;i++) schedule[i]=-1;
    printf("------------------------------------------");
    printf("\n               Unsorted                  \n");
    printsq();
    bubble();
    printf("-------------------------------------------");
    printf("\n               Sorted                  \n");
    printsq();
    printf("--------------Final Transaction schedule----------------------\n");
    job_sq();
    for(int i=0;i<n;i++)
    {
        printf("%d\n",schedule[i]);
    }
    return 0;
}
