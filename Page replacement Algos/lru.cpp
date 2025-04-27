#include<bits/stdc++.h>
using namespace std;

int main() {
    int page[100], frame[100], pageFaults = 0, frames, pages;
    vector<int> lastUsedTime;  // To store the last access time of each page

    cout << "Enter number of pages: ";
    cin >> pages;

    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "Enter the pages: ";
    for (int i = 0; i < pages; i++) {
        cin >> page[i];
    }

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;  // Initialize all frames as empty
    }

    for (int i = 0; i < pages; i++) {
        bool pageFound = false;

        // Check if the page is already present in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                pageFound = true;
                lastUsedTime[j] = i;  // Update the last used time of this page
                break;
            }
        }

        // If the page is not found, we have a page fault
        if (!pageFound) {
            bool emptyFound = false;

            // First, check for any empty frame
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    pageFaults++;
                    lastUsedTime.push_back(i);  // Record the last used time for this new page
                    emptyFound = true;
                    break;
                }
            }

            // If no empty frame, apply LRU replacement
            if (!emptyFound) {
                // Find the least recently used page
                int lruIndex = min_element(lastUsedTime.begin(), lastUsedTime.end()) - lastUsedTime.begin();
                frame[lruIndex] = page[i];  // Replace the least recently used page
                pageFaults++;
                lastUsedTime[lruIndex] = i;  // Update the last used time of the replaced page
            }
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    cout << "Final Frames: ";
    for (int i = 0; i < frames; i++) {
        cout << frame[i] << " ";
    }
    cout << endl;

    return 0;
}