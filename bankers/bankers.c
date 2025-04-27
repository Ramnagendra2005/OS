#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int main() {
    int n, m; // Number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int processes[n]; // Process IDs
    for (int i = 0; i < n; i++) {
        processes[i] = i;
    }

    int available[m]; // Available resources
    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    int max[n][m]; // Maximum resources required by each process
    printf("Enter the maximum resources required by each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    int allocation[n][m]; // Allocated resources for each process
    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    int need[n][m]; // Resources needed by each process
    bool finish[n];  // Finish flag for each process
    int safeSeq[n];  // Safe sequence
    int work[m];     // Work vector
    int count = 0;

    // Initialize finish array to false
    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }

    // Calculate the Need matrix (Need = Max - Allocation)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize work with available resources
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    while (count < n) {
        bool found = false;

        // Try to find a process that can finish
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                // Check if process p can be completed
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }
                // If process can be completed, allocate its resources to work and mark it as finished
                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        // If no process could be found that can complete, the system is in a deadlock state
        if (!found) {
            printf("The system is in a deadlock state.\n");
            return 0;
        }
    }

    // If all processes can complete, print the safe sequence
    printf("The system is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}
