#include<stdio.h>
struct fcfs
{
   int pid,btime,wtime,ttime;
}p[10];

int main()
{
    int total_waiting_time=0,total_turn_around_time=0,i,n;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    for (i =0;i<n;i++)
    {
        p[i].pid=1;
        printf("Enter the burst time of p%d : ",i+1);
        scanf("%d",&p[i].btime);
    }
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for(i=0;i<n;i++)
    {
      p[i].wtime=p[i-1].wtime+p[i-1].btime;
      p[i].ttime=p[i].wtime+p[i].btime;
      total_turn_around_time+=p[i].ttime;
      total_waiting_time+=p[i].wtime;
    }
    printf("waiting time : %d\n",total_waiting_time);
    printf("turn around time : %d\n",total_turn_around_time);
    printf("Average waiting time : %d \n",total_waiting_time/n);
    printf("Average turn around time : %d \n",total_turn_around_time/n);
}