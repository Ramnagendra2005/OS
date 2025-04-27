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

        // Check if page already in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            bool emptyFound = false;

            // Check if empty frame available
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    pageFaults++;
                    emptyFound = true;
                    break;
                }
            }

            // If no empty frame, apply optimal replacement
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

        // Optional: print frames after each page
        cout << "Frames after inserting page " << page[i] << ": ";
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                cout << frame[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
    
    return 0;
}
