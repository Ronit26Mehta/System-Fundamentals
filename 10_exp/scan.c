#include <stdio.h>
#define size 100

int cylinders[size];
int request;
int cylinder_size;
int seektime;
int totalmoment;
int total_seek_time;
int temporary[size];

void SCAN(int cylinders[], int temporary[], int cylinder_size, int request, int seektime);

int main() {
    printf("\t-----RONITSATISHMEHTA 60009230207-------\n");
    printf("\t--------SCAN SIMULATION----------------\n");
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
    for (int i = 1; i <= cylinder_size; i++) {
        temporary[i] = cylinders[i - 1];
    }

    SCAN(cylinders, temporary, cylinder_size, request, seektime);

    printf("\nTOTAL movement:%d", totalmoment);
    printf("\nTOTAL seek time:%d\n", total_seek_time);

    return 0;
}

void SCAN(int cylinders[], int temporary[], int cylinder_size, int request, int seektime) {
    int temp1, temp2, result;
    int head_position = request;
    printf("\nThe iterations:");

    // Sort the temporary array
    for (int i = 0; i <= cylinder_size; i++) {
        for (int j = i + 1; j <= cylinder_size; j++) {
            if (temporary[i] > temporary[j]) {
                int temp = temporary[i];
                temporary[i] = temporary[j];
                temporary[j] = temp;
            }
        }
    }

    // Find the index of head position
    int index;
    for (index = 0; index <= cylinder_size; index++) {
        if (temporary[index] == head_position) {
            break;
        }
    }

    // Move towards the right
    for (int i = index; i <= cylinder_size; i++) {
        temp1 = temporary[i];
        temp2 = temporary[i + 1];
        result = temp1 - temp2;
        totalmoment += (result < 0) ? -result : result;
        printf("\t|%d - %d|+", temp1, temp2);
    }

    // Move towards the left
    for (int i = index - 1; i >= 0; i--) {
        temp1 = temporary[i];
        temp2 = temporary[i + 1];
        result = temp1 - temp2;
        totalmoment += (result < 0) ? -result : result;
        printf("\t|%d - %d|+", temp1, temp2);
    }

    total_seek_time = totalmoment * seektime;
}
