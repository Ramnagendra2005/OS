#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], at[20], i, j, quantum;
    float avgwt = 0, avgtat = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and arrival time for each process
    printf("Enter the burst time and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
    }

    // Input the time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Initialize waiting time and turnaround time
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }

    // Round robin scheduling with arrival time
    int remaining[20];
    for (i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    int time = 0, completed = 0;
    while (completed < n) {
        for (i = 0; i < n; i++) {
            // Process only if it has arrived and has remaining burst time
            if (at[i] <= time && remaining[i] > 0) {
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    wt[i] = time - bt[i] - at[i]; // Waiting time = time spent - burst time - arrival time
                    tat[i] = time - at[i]; // Turnaround time = time - arrival time
                    remaining[i] = 0;
                    completed++;
                }
            }
        }
    }

    // Gantt chart display
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
        printf(" P%d |", i + 1);
    }
    printf("\n ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    // Detailed table display
    printf("\nProcess | Burst Time | Arrival Time | Waiting Time | Turnaround Time\n");
    printf("-------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("  P%d    |    %d     |      %d      |     %d      |      %d\n", 
            i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    // Calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    // Display average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f", avgtat);

    return 0;
}