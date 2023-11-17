#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 16
#define WORD_SIZE 4

typedef struct {
    int valid;
    int tag;
    char data[WORD_SIZE];
} CacheLine;

CacheLine cache[CACHE_SIZE];

void initializeCache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].valid = 0;
        cache[i].tag = -1;
    }
}

void displayCache() {
    printf("\nCache Content:\n");
    printf("Index\t| Valid\t| Tag\t| Data\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("%d\t| %d\t| %d\t| %s\n", i, cache[i].valid, cache[i].tag, cache[i].data);
    }
}

void cacheMappingFullyAssociative(int address) {
    int index = -1;
    int tag = address / CACHE_SIZE;

    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].valid && cache[i].tag == tag) {
            printf("Cache Hit!\n");
            displayCache();
            return;
        }

        if (!cache[i].valid) {
            index = i;
        }
    }

    if (index != -1) {
        cache[index].valid = 1;
        cache[index].tag = tag;
        printf("Cache Miss! Data loaded into cache.\n");
        displayCache();
    } else {
        printf("Cache is full. Cannot load more data.\n");
    }
}

void addToCache(int address, int data) {
    int index = rand() % CACHE_SIZE;
    cache[index].valid = 1;
    cache[index].tag = address / WORD_SIZE;
    cache[index].data = data;
}

void tagAndWordSizeCalculator() {
    printf("Tag Size: %d bits\n", sizeof(int) * 8 - __builtin_clz(CACHE_SIZE));
    printf("Word Size: %d bits\n", sizeof(int) * 8 - __builtin_clz(WORD_SIZE));
}

int main() {
    int choice, address, data;

    initializeCache();

    do {
        printf("\nCache Mapping Menu:\n");
        printf("1. Display Cache\n");
        printf("2. Cache Mapping (Fully Associative)\n");
        printf("3. Add to Cache\n");
        printf("4. Tag and Word Size Calculator\n");
        printf("5. Exit\n");
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
                printf("Enter memory address: ");
                scanf("%d", &address);
                printf("Enter data: ");
                scanf("%d", &data);
                addToCache(address, data);
                break;
            case 4:
                tagAndWordSizeCalculator();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
