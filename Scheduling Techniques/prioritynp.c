#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], pr[20], at[20], ct[20];
    int i, j, time = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

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

    // Sort based on priority (ascending order)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp;
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
            }
        }
    }

    // Calculate Completion Times, Waiting Times, Turnaround Times
    time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i]; // CPU remains idle if process arrives late
        }
        time += bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];      // Turnaround time = Completion - Arrival
        wt[i] = tat[i] - bt[i];       // Waiting time = Turnaround - Burst

        avgwt += wt[i];
        avgtat += tat[i];
    }

    // Process table
    printf("\nProcess\tBurst Time\tPriority\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], pr[i], at[i], ct[i], wt[i], tat[i]);
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
        for (j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("P%d", i + 1);
        for (j = 0; j < bt[i] - 1; j++) printf(" ");
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
    for (i = 0; i < n; i++) {
        if (ct[i] < 10)
            printf("  %d", ct[i]);
        else
            printf(" %d", ct[i]);
    }
    printf("\n");

    return 0;
}