#include <stdio.h>
#define size 100

int cylinders[size];
int request;
int cylinder_size;
int seektime;
int totalmoment;
int total_seek_time;
int temporary[size];

void FCFS(int cylinders[], int temporary[], int cylinder_size, int request, int seektime);

void main() {
    printf("\t-----RONITSATISHMEHTA 60009230207-------\n");
    printf("\t--------FCFS SIMULATION----------------\n");
    printf("\nEnter the size of disk:");
    scanf("%d", &cylinder_size);

    printf("\nStart entering cylinders for disk:");
    for (int i = 0; i < cylinder_size; i++) {
        scanf("%d", &cylinders[i]);
    }

    printf("\nEnter Seek time:");
    scanf("%d", &seektime);

    printf("\nEnter request disk:");
    scanf("%d", &request);

    temporary[0] = request;
    for (int i = 1; i <=cylinder_size; i++) {
        temporary[i] = cylinders[i - 1];
    }

    FCFS(cylinders, temporary, cylinder_size, request, seektime);

    printf("\nTOTAL movement:%d", totalmoment);
    printf("\nTOTAL seek time:%d\n", total_seek_time);

}

void FCFS(int cylinders[], int temporary[], int cylinder_size, int request, int seektime) {
    int temp1, temp2, result;
    printf("\nThe iterations:");
    for (int i = 0; i < cylinder_size; i++) {
        temp1 = temporary[i];
        temp2 = temporary[i + 1];
        result = temp1 - temp2;
        totalmoment += (result < 0) ? -result : result;  
        printf("\t|%d - %d|+", temp1, temp2);
    }
    total_seek_time = totalmoment * seektime;
}
