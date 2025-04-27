#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], pr[20], at[20], i, j;
    float avgwt = 0, avgtat = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times, priorities, and arrival times for each process
    printf("Enter the burst time, priority, and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
    }

    // Sort the processes based on priority (ascending order of priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            // Ensure waiting time is calculated based on arrival time
            if (at[i] > wt[j]) {
                wt[i] = wt[j]; // If the process arrives later, start from its arrival time
            }
            wt[i] += bt[j]; // Waiting time is sum of burst times of all previous processes
        }
    }

    // Display process table: Burst Time, Waiting Time, Turnaround Time
    printf("\nProcess\tBurst Time\tPriority\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst Time + Waiting Time
        avgwt += wt[i];
        avgtat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], pr[i], at[i], wt[i], tat[i]);
    }

    // Calculate and display average waiting time and turnaround time
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