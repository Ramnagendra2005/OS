#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, head, min, seek = 0, diff, index;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];
    printf("Enter the requests:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Traversal Order: %d ", head);
    for (i = 0; i < n; i++)
    {
        min = 9999;
        for (j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                diff = abs(head - req[j]);
                if (diff < min)
                {
                    min = diff;
                    index = j;
                }
            }
        }
        seek += min;
        head = req[index];
        visited[index] = 1;
        printf("-> %d ", head);
    }

    printf("\nTotal seek time: %d\n", seek);
    return 0;
}
