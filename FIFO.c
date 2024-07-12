#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3  // Maximum number of frames in memory

// Function to check if a page exists in current frames
bool isInFrames(int page, int frames[], int frame_count) {
    for (int i = 0; i < frame_count; ++i) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the index of the oldest page in frames
int findOldestIndex(int age[], int frame_count) {
    int min_age = age[0];
    int oldest_index = 0;
    for (int i = 1; i < frame_count; ++i) {
        if (age[i] < min_age) {
            min_age = age[i];
            oldest_index = i;
        }
    }
    return oldest_index;
}

// Function to simulate FIFO page replacement algorithm
void simulateFIFO(int pages[], int page_count) {
    int frames[MAX_FRAMES];  // Array to store frames
    int frame_count = 0;     // Number of frames currently occupied
    int page_faults = 0;     // Count of page faults
    int age[MAX_FRAMES];     // Array to store age of each page in frames

    // Initialize frames and age array
    for (int i = 0; i < MAX_FRAMES; ++i) {
        frames
