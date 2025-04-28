#include <stdio.h>

int main() {
    int n, bt[20], rt[20], at[20];
    int wt[20], tat[20], ct[20];
    int i, sm, t = 0, end;
    float avgwt = 0, avgtat = 0;
    int comp = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        rt[i] = bt[i];
    }

    printf("\nGantt Chart:\n|");

    while (comp != n) {
        sm = -1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= t) {
                if (sm == -1 || rt[i] < rt[sm])
                    sm = i;
            }
        }

        if (sm == -1) {
            t++;
            continue;
        }

        printf(" P%d |", sm + 1);

        rt[sm]--;
        t++;

        if (rt[sm] == 0) {
            comp++;
            end = t;
            ct[sm] = end;
            tat[sm] = ct[sm] - at[sm];
            wt[sm] = tat[sm] - bt[sm];
        }
    }

    printf("\n\nProcess\tBT\tAT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], at[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgwt / n);
    printf("Average Turnaround Time: %.2f\n", avgtat / n);

    return 0;
}