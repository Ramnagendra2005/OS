#include <stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 100

int main() {
    int page[MAX_PAGES], frame[MAX_FRAMES], pageFaults = 0, frames, pages;
    int lastUsedTime[MAX_FRAMES];  // To store the last access time of each page

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter the pages: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    // Initialize frames as empty (indicated by -1)
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    // Process each page in the sequence
    for (int i = 0; i < pages; i++) {
        int pageFound = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                pageFound = 1;
                lastUsedTime[j] = i;  // Update the last used time of this page
                break;
            }
        }

        // If the page is not found, it's a page fault
        if (!pageFound) {
            int emptyFound = 0;

            // First, check for any empty frame
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    pageFaults++;
                    lastUsedTime[j] = i;  // Record the last used time for this new page
                    emptyFound = 1;
                    break;
                }
            }

            // If no empty frame, apply LRU replacement
            if (!emptyFound) {
                // Find the least recently used page by comparing the last used times
                int lruIndex = 0;
                for (int j = 1; j < frames; j++) {
                    if (lastUsedTime[j] < lastUsedTime[lruIndex]) {
                        lruIndex = j;
                    }
                }
                frame[lruIndex] = page[i];  // Replace the least recently used page
                pageFaults++;
                lastUsedTime[lruIndex] = i;  // Update the last used time of the replaced page
            }
        }
    }

    // Output the results
    printf("Total Page Faults: %d\n", pageFaults);
    printf("Final Frames: ");
    for (int i = 0; i < frames; i++) {
        printf("%d ", frame[i]);
    }
    printf("\n");

    return 0;
}