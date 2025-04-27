#include<stdio.h>
int main(){
    // priority scheduling preemptive with gantt chart
    int n, bt[20], wt[20], tat[20], pr[20], i, j;
    float avgwt = 0, avgtat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Input burst time for each process
    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    // Input priority for each process
    printf("Enter the priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &pr[i]);
    }
    
    // Sort the processes based on priority
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                // Swap priorities
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                
                // Swap burst times accordingly
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    
    // Calculate waiting time for each process
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }

    // Output the process table with burst time, waiting time, and turnaround time
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst Time + Waiting Time
        avgwt += wt[i];
        avgtat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    
    // Calculate average waiting time and average turnaround time
    avgwt /= n;
    avgtat /= n;
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    printf(" ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i] - 1; j++) {
            printf(" ");
        }
        printf("P%d", i + 1); // Process display
        for (j = 0; j < bt[i] - 1; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");
    
    // Display completion times in the Gantt chart
    printf("0");
    int time = 0;
    for (i = 0; i < n; i++) {
        time += bt[i];
        if (time < 10)
            printf("  %d", time);  // Aligning single-digit times
        else
            printf(" %d", time);
    }
    printf("\n");

    return 0;
}
