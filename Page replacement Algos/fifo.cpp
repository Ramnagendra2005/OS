#include <iostream>
using namespace std;

int main() {
    // FIFO Page Replacement Algorithm
    //Uses smiple variable names
    int page[10], frame[10], pageFaults = 0, frames, pages;
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
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                pageFound = true;
                break;
            }
        }
        if (!pageFound) {
            frame[pageFaults % frames] = page[i];
            pageFaults++;
        }
    }
    cout << "Page Faults: " << pageFaults << endl;
    cout << "Frames: ";
    for (int i = 0; i < frames; i++) {
        cout << frame[i] << " ";
    }
    cout << endl;
    return 0;
}
