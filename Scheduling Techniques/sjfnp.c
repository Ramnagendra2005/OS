#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Define arrays of size n after getting user input
    int bt[n], at[n], wt[n], tat[n], ct[n], pid[n];
    float avgwt = 0, avgtat = 0;
    int i, j;

    printf("Enter the burst time and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Process %d\n", pid[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
    }

    // Sort by arrival time, then by burst time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
                int temp;

                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];

        time += bt[i];
        ct[i] = time;
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nProcess\tPID\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\tP%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, pid[i], bt[i], at[i], ct[i], wt[i], tat[i]);
    }

    avgwt /= n;
    avgtat /= n;
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    // Gantt Chart
    printf("\nGantt Chart:\n ");
    for (i = 0; i < n; i++) {
        printf("----");
    }
    printf("-\n|");
    for (i = 0; i < n; i++) {
        printf(" P%d |", pid[i]);
    }
    printf("\n ");
    for (i = 0; i < n; i++) {
        printf("----");
    }
    printf("-\n");

    printf("0");
    for (i = 0; i < n; i++) {
        if (ct[i] < 10)
            printf("   %d", ct[i]);
        else
            printf("  %d", ct[i]);
    }
    printf("\n");

    return 0;
}
