#include <stdio.h>
int main() {
    int i, j, n, burst[10], prio[10], comp[10], wt[10], tat[10], temp1, temp2, temp3, process[10];
    float total_tatime = 0.0, total_wtime = 0.0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the burst time of p%d: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Enter the priority of p%d: ", i + 1);
        scanf("%d", &prio[i]);
        process[i] = i + 1; 
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (prio[i] > prio[j]) {
                temp1 = burst[i];
                burst[i] = burst[j];
                burst[j] = temp1;
                temp2 = prio[i];
                prio[i] = prio[j];
                prio[j] = temp2;
                temp3 = process[i];
                process[i] = process[j];
                process[j] = temp3;
            }
        }
    }
    comp[0] = burst[0];
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        comp[i] = burst[i] + comp[i - 1];
    }
    for (i = 0; i < n; i++) {
        tat[i] = comp[i];
        wt[i] = tat[i] - burst[i];
        total_tatime += tat[i];
        total_wtime += wt[i];
    }
    printf("\nTotal waiting time: %.2f\n", total_wtime);
    printf("Total turn around time: %.2f\n", total_tatime);
    printf("Average waiting time: %.2f\n", total_wtime / n);
    printf("Average turn around time: %.2f\n", total_tatime / n);
    return 0;
}
