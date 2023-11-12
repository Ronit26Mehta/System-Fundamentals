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

void fifo(int refernce_string[], int frame_size, int page_size);

void main() {
    printf("\t\tRonit Satish Mehta 60009230207 \n");
    printf("\t\t---------FIFO SIMULATOR---------\n");
    printf("\nEnter Frame Size: ");
    scanf("%d", &frame_size);
    printf("\nEnter the size of refernce string of pages: ");
    scanf("%d", &page_size);
    for (int i = 0; i < page_size; i++) {
        scanf("%d", &refernce_string[i]);
    }
    fifo(refernce_string, frame_size, page_size);
    printf("\nThe Page hit is:%d", page_hit);
    printf("\nThe page fault is:%d", page_fault);
    printf("\nThe hit ratio is:%d", hit_ratio);
}

void fifo(int refernce_string[], int frame_size, int page_size) {
    int frame_queue[size];
    int front = 0, rear = 0;

    for (int i = 0; i < page_size; i++) {
        int page = refernce_string[i];
        bool page_hit_flag = false;

        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                page_hit++;
                page_hit_flag = true;
                break;
            }
        }

        if (!page_hit_flag) {
            page_fault++;

            if (rear < frame_size) {
                frames[rear++] = page;
                frame_queue[rear - 1] = rear - 1;
            } else {
                int replaced_page = frame_queue[front];
                frames[replaced_page] = page;
                frame_queue[rear++] = replaced_page;
                front = (front + 1) % frame_size; // Update front circularly
                printf("\nIteration %d (Page Replacement):\n", i + 1);
                printf("Frames: ");
                for (int k = 0; k < frame_size; k++) {
                    printf("%d ", frames[k]);
                }
                printf("\n");
                printf("Page %d replaces page %d in frame %d\n", page, frames[replaced_page], replaced_page);
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
