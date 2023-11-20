#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 8
#define BLOCK_SIZE 4
#define NUM_SETS 4  // Set-associativity, change as needed

typedef struct {
    int valid;
    int tag;
    // Add other necessary fields for your cache structure
} CacheLine;

typedef struct {
    CacheLine lines[CACHE_SIZE / NUM_SETS][NUM_SETS];
    // Add other necessary fields for your cache structure
} SetAssociativeCache;

SetAssociativeCache myCache;

int hits = 0;
int accesses = 0;

void initializeCache() {
    for (int i = 0; i < CACHE_SIZE / NUM_SETS; i++) {
        for (int j = 0; j < NUM_SETS; j++) {
            myCache.lines[i][j].valid = 0;
            // Initialize other cache fields as needed
        }
    }
}

void displayCache() {
    printf("Cache Mapping:\n");

    for (int i = 0; i < CACHE_SIZE / NUM_SETS; i++) {
        printf("Set %d:\n", i);

        for (int j = 0; j < NUM_SETS; j++) {
            printf("  Way %d: ", j);

            if (myCache.lines[i][j].valid) {
                printf("%x: ", myCache.lines[i][j].tag);

                // Print additional data or modify this part as needed
                for (int k = 0; k < NUM_SETS; k++) {
                    if (k == j) {
                        printf("Hit%d ", k + 1);
                    } else {
                        printf("0 ");
                    }
                }
            } else {
                printf("Miss: ");
                for (int k = 0; k < NUM_SETS; k++) {
                    printf("0 ");
                }
            }

            printf("\n");
        }
        printf("\n");
    }
}

int isCacheHit(int tag) {
    for (int i = 0; i < CACHE_SIZE / NUM_SETS; i++) {
        for (int j = 0; j < NUM_SETS; j++) {
            if (myCache.lines[i][j].valid && myCache.lines[i][j].tag == tag) {
                return i; // Cache hit, return set index
            }
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

    int address;

    while (fscanf(file, "%x", &address) != EOF) {
        accesses++;
        int setIndex = isCacheHit(address / BLOCK_SIZE);

        if (setIndex != -1) {
            hits++;
            printf("Cache Hit! ");
        } else {
            printf("Cache Miss! ");
            // Simulate cache load operation here
        }

        printf("Address: %x\n", address);
    }

    fclose(file);
}

void tagAndWordSizeCalculator() {
    printf("Tag Size: %d bits\n", sizeof(int) * 8 - __builtin_clz(CACHE_SIZE));
    printf("Word Size: %d bits\n", sizeof(int) * 8 - __builtin_clz(BLOCK_SIZE));
}

void displayMemory(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Error opening file %s.\n", fileName);
        return;
    }

    printf("\nMemory Content:\n");
    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        // Display memory in a vertical hash table format
        printf("[%d]\n", value);
    }
    printf("\n");

    fclose(file);
}

void displayHitRatio() {
    if (accesses > 0) {
        double hitRate = (double)hits / accesses;
        printf("Hit Rate: %.2f%%\n", hitRate * 100);
    } else {
        printf("No accesses recorded yet.\n");
    }
}

int main() {
    int choice;
    char fileName[100];

    initializeCache();

    do {
        printf("Cache Simulator Menu:\n");
        printf("1. Load Trace File\n");
        printf("2. Display Cache\n");
        printf("3. Display Hit Rate\n");
        printf("4. Display Memory\n");
        printf("5. Tag and Word Size Calculator\n");
        printf("6. Exit\n");
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
                displayHitRatio();
                break;
            case 4:
                printf("Enter the memory file name: ");
                scanf("%s", fileName);
                displayMemory(fileName);
                break;
            case 5:
                tagAndWordSizeCalculator();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
