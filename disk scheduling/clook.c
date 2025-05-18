#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n, i, head, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n + 1];
    printf("Enter the requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    req[n++] = head;
    qsort(req, n, sizeof(int), compare);

    int pos;
    for (i = 0; i < n; i++)
        if (req[i] == head)
        {
            pos = i;
            break;
        }

    printf("Traversal Order: %d ", head);
    for (i = pos + 1; i < n; i++)
    {
        seek += abs(head - req[i]);
        head = req[i];
        printf("-> %d ", head);
    }

    for (i = 0; i < pos; i++)
    {
        seek += abs(head - req[i]);
        head = req[i];
        printf("-> %d ", head);
    }

    printf("\nTotal seek time: %d\n", seek);
    return 0;
}

