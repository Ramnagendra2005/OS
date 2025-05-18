#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Traversal Order: %d ", head);
    for (i = 0; i < n; i++)
    {
        seek += abs(head - req[i]);
        head = req[i];
        printf("-> %d ", head);
    }

    printf("\nTotal seek time: %d\n", seek);
    return 0;
}
