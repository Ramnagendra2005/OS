#include<stdio.h>
int main() {
    int n, bt[20], wt[20], tat[20], i, j;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; // Waiting time for first process is 0
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j]; // waiting time is sum of burst times of previous processes
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // turnaround time is burst time + waiting time
        avgwt += wt[i];
        avgtat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    avgwt /= n;
    avgtat /= n;
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
