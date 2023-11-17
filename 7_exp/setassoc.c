#include <stdio.h>
#include <stdlib.h>

#define CACHE_SETS 4    
#define SET_SIZE 4      
#define WORD_SIZE 4     

typedef struct {
    int valid;
    int tag;
    char data[WORD_SIZE];
} CacheLine;

CacheLine cache[CACHE_SETS][SET_SIZE];

void initializeCache() {
    for (int i = 0; i < CACHE_SETS; i++) {
        for (int j = 0; j < SET_SIZE; j++) {
            cache[i][j].valid = 0;
            cache[i][j].tag = -1;
        }
    }
}

void displayCache() {
    printf("\nCache Content:\n");
    printf("Set\tIndex\t| Valid\t| Tag\t| Data\n");
    for (int i = 0; i < CACHE_SETS; i++) {
        for (int j = 0; j < SET_SIZE; j++) {
            printf("%d\t%d\t| %d\t| %d\t| %s\n", i, j, cache[i][j].valid, cache[i][j].tag, cache[i][j].data);
        }
    }
}

void cacheMappingSetAssociative(int address) {
    int set = address % CACHE_SETS;
    int tag = address / CACHE_SETS;


    for (int j = 0; j < SET_SIZE; j++) {
        if (cache[set][j].valid && cache[set][j].tag == tag) {
            printf("Cache Hit!\n");
            displayCache();
            return;
        }
    }


    for (int j = 0; j < SET_SIZE; j++) {
        if (!cache[set][j].valid) {
            cache[set][j].valid = 1;
            cache[set][j].tag = tag;
            printf("Cache Miss! Data loaded into cache.\n");
            displayCache();
            return;
        }
    }

   
    cache[set][0].tag = tag;
    printf("Cache Miss! Data loaded into cache.\n");
    displayCache();
}

void addToCache(int address, int data) {
    int set = address % CACHE_SETS;
    int index = rand() % SET_SIZE;
    cache[set][index].valid = 1;
    cache[set][index].tag = address / WORD_SIZE;
    cache[set][index].data = data;
}

void tagAndWordSizeCalculator() {
    printf("Tag Size: %d bits\n", sizeof(int) * 8 - __builtin_clz(CACHE_SETS));
    printf("Word Size: %d bits\n", sizeof(int) * 8 - __builtin_clz(WORD_SIZE));
}

int main() {
    int choice, address, data;

    initializeCache();

    do {
        printf("\nCache Mapping Menu:\n");
        printf("1. Display Cache\n");
        printf("2. Cache Mapping (Fully Associative)\n");
        printf("3. Cache Mapping (Set Associative)\n");
        printf("4. Add to Cache\n");
        printf("5. Tag and Word Size Calculator\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCache();
                break;
            case 2:
                printf("Enter the memory address: ");
                scanf("%d", &address);
                cacheMappingFullyAssociative(address);
                break;
            case 3:
                printf("Enter the memory address: ");
                scanf("%d", &address);
                cacheMappingSetAssociative(address);
                break;
            case 4:
                printf("Enter memory address: ");
                scanf("%d", &address);
                printf("Enter data: ");
                scanf("%d", &data);
                addToCache(address, data);
                break;
            case 5:
                tagAndWordSizeCalculator();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
