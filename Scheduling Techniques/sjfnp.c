#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], at[20], ct[20], i, j;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
    }

    // Sort based on arrival time and burst time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i]; // CPU idle till process arrives

        time += bt[i];
        ct[i] = time;
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // Turnaround time = Completion Time - Arrival Time
        wt[i] = tat[i] - bt[i]; // Waiting time = Turnaround Time - Burst Time

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], ct[i], wt[i], tat[i]);
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
        printf(" P%d |", i + 1);
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