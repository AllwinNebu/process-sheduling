#include<stdio.h>
struct sjf
{
    int pid,btime,wtime,ttime;
} p[10];
int main()
{
    int i,n,j,total_waiting_time=0,total_turn_around_time=0;
    struct sjf temp;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of p%d : \n",i+1);
        scanf("%d",&p[i].btime);
    }
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (p[i].btime > p[j].btime)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            } 
        }
    }
    for(i=0;i<n;i++)
    {
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        total_waiting_time += p[i].wtime;
        total_turn_around_time += p[i].ttime;
    }
    printf("\nWaiting time : %d",total_waiting_time);
    printf("\n Average waiting time : %d",total_waiting_time/n);
    printf("\n Turn around time : %d",total_turn_around_time);
    printf("\n Average turn around time : %d",total_turn_around_time/n);
}