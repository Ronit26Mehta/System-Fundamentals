#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 8
#define BLOCK_SIZE 4

typedef struct {
    int valid;
    int tag;
    // Add other necessary fields for your cache structure
} CacheLine;

typedef struct {
    CacheLine lines[CACHE_SIZE];
    // Add other necessary fields for your cache structure
} Cache;

Cache myCache;

void initializeCache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        myCache.lines[i].valid = 0;
        // Initialize other cache fields as needed
    }
}

void displayCache() {
    printf("Cache:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("[%d] Valid: %d, Tag: %x\n", i, myCache.lines[i].valid, myCache.lines[i].tag);
        // Display other cache fields as needed
    }
    printf("\n");
}

int isCacheHit(int tag) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (myCache.lines[i].valid && myCache.lines[i].tag == tag) {
            return i; // Cache hit, return index
        }
    }
    return -1; // Cache miss
}

void processTraceFile(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Error opening file %s.\n", fileName);
        return;
    }

    // Process trace file here

    fclose(file);
}

int main() {
    int choice;
    char fileName[100];

    initializeCache();

    do {
        printf("Cache Simulator Menu:\n");
        printf("1. Load Trace File\n");
        printf("2. Display Cache\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the trace file name: ");
                scanf("%s", fileName);
                processTraceFile(fileName);
                break;
            case 2:
                displayCache();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
