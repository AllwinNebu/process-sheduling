#include <stdio.h>

struct Process {
    int pid; 
    int bt;   
    int at;   
    int rt;   
    int wt;   
    int tat;  
};

void calculateTimes(struct Process proc[], int n) {
    int complete = 0, t = 0, minm = 10000;
    int shortest = 0, finish_time;
    int check = 0, total_wt = 0, total_tat = 0;
    
  
    for (int i = 0; i < n; i++) {
        proc[i].rt = proc[i].bt;
    }
    
    while (complete != n) {
        
        for (int j = 0; j < n; j++) {
            if ((proc[j].at <= t) && (proc[j].rt < minm) && proc[j].rt > 0) {
                minm = proc[j].rt;
                shortest = j;
                check = 1;
            }
        }
        
        if (check == 0) {
            t++;
            continue;
        }
        
        proc[shortest].rt--;
        
        minm = proc[shortest].rt;
        if (minm == 0) {
            minm = 10000;
        }
        
        if (proc[shortest].rt == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
            
            proc[shortest].wt = finish_time - proc[shortest].bt - proc[shortest].at;
            if (proc[shortest].wt < 0) {
                proc[shortest].wt = 0;
            }
            
            proc[shortest].tat = proc[shortest].bt + proc[shortest].wt;
            total_wt += proc[shortest].wt;
            total_tat += proc[shortest].tat;
        }
        t++;
    }
    
    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / n);
}

void printGanttChart(struct Process proc[], int n) {
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < proc[i].bt; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < proc[i].bt - 1; j++) {
            printf(" ");
        }
        printf("P%d", proc[i].pid);
        for (int j = 0; j < proc[i].bt - 1; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < proc[i].bt; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d", proc[i].at);
        for (int j = 0; j < proc[i].bt; j++) {
            printf("  ");
        }
    }
    printf("%d\n", proc[n-1].at + proc[n-1].bt);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].at, &proc[i].bt);
        proc[i].pid = i + 1;
    }
    
    calculateTimes(proc, n);
    printGanttChart(proc, n);
    
    return 0;
}
