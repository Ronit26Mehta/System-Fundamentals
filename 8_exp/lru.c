#include<stdio.h>
#include <stdbool.h>
#define size 100
int refernce_string[size];
int frames[size];
int frame_size;
int page_size;
int hit_ratio;
int page_hit;
int page_fault;
void lru(int refernce_string[], int frame_size, int page_size);
void main() {
    printf("\t\tRonit Satish Mehta 60009230207 \n");
    printf("\t\t---------LRU SIMULATOR---------\n");
    printf("\nEnter Frame Size: ");
    scanf("%d", &frame_size);
    printf("\nEnter the size of refernce string of pages: ");
    scanf("%d", &page_size);
    for (int i = 0; i < page_size; i++) {
        scanf("%d", &refernce_string[i]);
    }
    lru(refernce_string, frame_size, page_size);
    printf("\nThe Page hit is:%d", page_hit);
    printf("\nThe page fault is:%d", page_fault);
    printf("\nThe hit ratio is:%d", hit_ratio);
}
void lru(int refernce_string[], int frame_size, int page_size) {
    int frame_queue[size];
    int front = 0, rear = 0;
    int time[size];
    int clock = 0;

    for (int i = 0; i < frame_size; i++) {
        frames[i] = -1;
        time[i] = -1;
    }

    for (int i = 0; i < page_size; i++) {
        int page = refernce_string[i];
        bool page_hit_flag = false;

        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                page_hit++;
                page_hit_flag = true;
                time[j] = clock++;
                break;
            }
        }

        if (!page_hit_flag) {
            page_fault++;

            if (rear < frame_size) {
                frames[rear] = page;
                time[rear] = clock++;
                frame_queue[rear++] = rear - 1;
            } else {
                int min_time_index = 0;
                for (int j = 1; j < frame_size; j++) {
                    if (time[j] < time[min_time_index]) {
                        min_time_index = j;
                    }
                }
                frames[min_time_index] = page;
                time[min_time_index] = clock++;
                frame_queue[rear++] = min_time_index;
                front = (front + 1) % frame_size; 
                printf("\nIteration %d (Page Replacement):\n", i + 1);
                printf("Frames: ");
                for (int k = 0; k < frame_size; k++) {
                    printf("%d ", frames[k]);
                }
                printf("\n");
                printf("Page %d replaces page %d in frame %d\n", page, frames[min_time_index], min_time_index);
            }

            printf("\nIteration %d:\n", i + 1);
            printf("Frames: ");
            for (int k = 0; k < frame_size; k++) {
                printf("%d ", frames[k]);
            }
            printf("\n");
            printf("Page %d loaded into frame %d\n", page, rear - 1);
        } else {
            printf("\nIteration %d (Page Hit):\n", i + 1);
            printf("Frames: ");
            for (int k = 0; k < frame_size; k++) {
                printf("%d ", frames[k]);
            }
            printf("\n");
        }
    }

    hit_ratio = (page_hit * 100) / page_size;
}
