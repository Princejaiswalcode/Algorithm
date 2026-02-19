#include<stdio.h>
int deadline[8]={4,5,6,6,4,2,2,2};
int profit[8]={20,60,70,65,25,80,10,22};
int transaction_id[8]={1,2,3,4,5,6,7,8};
int max_deadline=-1;
int n=sizeof(profit)/sizeof(profit[0]);
int schedule[8];

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
    for(int i=0;i<n;i++)
    {
        printf("T%d\t%d\t%d\n",transaction_id[i],profit[i],deadline[i]);
    }
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
    printf("---------------Unsorted------------------\n");
    printsq();
    bubble();
    printf("---------------Sorted--------------------\n");
    printsq();
    job_sq();
    printf("--------------Final Transaction schedule----------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",schedule[i]);
    }
    return 0;
}
