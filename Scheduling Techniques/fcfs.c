#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], at[20], i, j;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input Burst Time
    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Input Arrival Time
    printf("Enter the arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &at[i]);
    }

    wt[0] = 0; // Waiting time for first process is 0
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j]; // waiting time is sum of burst times of previous processes
        }
        wt[i] -= at[i]; // Adjust for arrival time
        if (wt[i] < 0) {
            wt[i] = 0; // If waiting time is negative, set it to 0
        }
    }

    // Calculate Turnaround Time
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
        avgwt += wt[i];
        avgtat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    avgwt /= n;   // Average Waiting Time
    avgtat /= n;  // Average Turnaround Time

    // Print average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    // Gantt Chart
    printf("\nGantt Chart:\n ");
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
        printf("P%d", i + 1);
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

    printf("0");
    int time = 0;
    for (i = 0; i < n; i++) {
        time += bt[i];
        if (time < 10)
            printf("  %d", time);  // for aligning single-digit times
        else
            printf(" %d", time);
    }
    printf("\n");

    return 0;
}