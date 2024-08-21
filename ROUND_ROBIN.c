#include<stdio.h>
int main()
{
    int i,j,n,time,remain,flag=0,ts,sum_wait =0,sum_turnaround =0,at[10],bt[10],re[10];
    printf("enter the nUmber of process : ");
    scanf("%d",&n);
    remain=n;
    for(i=0;i<n;i++)
    {
        printf("enter the arrival and burst time of p%d : ",i+1);
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        re[i]=bt[i];
    }
    printf("\nEnter the time slice : ");
    scanf("%d",&ts);
    for(time=0,i=0;remain!=0;)
    {
        if(re[i]<=ts && re[i]>0)
        {
            time+=re[i];
            re[i]=0;
            flag=1;
        }
        else if(re[i]>0)
        {
            re[i]-=ts;
            time+=ts;
        }
        if(re[i]==0 && flag==1)
        {
            remain--;
            sum_wait+=time-at[i]-bt[i];
            sum_turnaround+=time-at[i];
            flag=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if (at[i+1]<=time)
        {
           i++;     
        }
        else
        {
            i=0;
        }   
    }
    printf("\nTotal waiting time: %.2f\n", sum_wait);
    printf("Total turn around time: %.2f\n", sum_turnaround);
    printf("Average waiting time: %.2f\n", sum_wait / n);
    printf("Average turn around time: %.2f\n", sum_turnaround / n);
}