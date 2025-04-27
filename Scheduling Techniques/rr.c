#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], i, j, quantum;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Initializing waiting time and turnaround time
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }

    // Round robin scheduling
    int remaining[20];
    for (i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    wt[i] = time - bt[i];
                    tat[i] = time;
                    remaining[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    // Gantt chart
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

    // Displaying detailed table of all values
    printf("\nProcess | Burst Time | Waiting Time | Turnaround Time | Remaining Time\n");
    printf("-----------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("  P%d    |    %d     |     %d      |      %d         |       %d\n", 
            i + 1, bt[i], wt[i], tat[i] - bt[i], remaining[i]);
    }

    // Calculate average waiting time and turnaround time
    for (i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i] - bt[i];
    }

    avgwt /= n;
    avgtat /= n;

    // Display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f", avgtat);

    return 0;
}
