#include<bits/stdc++.h>
using namespace std;

int main() {
    int page[100], frame[100], pageFaults = 0, frames, pages;
    
    cout << "Enter number of pages: ";
    cin >> pages; 
    
    cout << "Enter number of frames: ";
    cin >> frames;
    
    cout << "Enter the pages: ";
    for (int i = 0; i < pages; i++) {
        cin >> page[i];
    }
    
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < pages; i++) {
        bool pageFound = false;

        // Check if page is already present
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                pageFound = true;
                break;
            }
        }

        // If not found, need to replace
        if (!pageFound) {
            bool emptyFound = false;

            // First check for empty frame
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    pageFaults++;
                    emptyFound = true;
                    break;
                }
            }

            // If no empty frame, apply Optimal Replacement
            if (!emptyFound) {
                int farthest = -1, index = -1;
                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < pages; k++) {
                        if (frame[j] == page[k]) {
                            break;
                        }
                    }
                    if (k > farthest) {
                        farthest = k;
                        index = j;
                    }
                }
                frame[index] = page[i];
                pageFaults++;
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
