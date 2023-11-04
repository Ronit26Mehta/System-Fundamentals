#include <stdio.h>
#include <stdlib.h>

#define size 10

int blocksize[size];
int file_size[size];
int process[size];
int fragment[size];
int block_no[size];
int block_used[size];
int temporary[size];
int temporary1[size];
void worst_fit(int blocksize[], int file_size[], int process[], int blocks_no, int file_no);

int main() {
    int blocks_no, file_no;

    printf("\n\tRonit Satish Mehta 60009230207\n");
    printf("\n\t--------WORST FIT CALCULATOR ---------\n");
    printf("Enter the number of blocks:\n");
    scanf("%d", &blocks_no);
    printf("Enter the number of files:\n");
    scanf("%d", &file_no);

    printf("Enter the block no:\n");
    for (int i = 0; i < blocks_no; i++) {
        scanf("%d", &process[i]);
    }
    printf("Enter the size of blocks:\n");
    for (int i = 0; i < blocks_no; i++) {
        printf("Block %d: ", i+1);
        scanf("%d", &blocksize[i]);
    }
    printf("Enter the size of files:\n");
    for (int i = 0; i < file_no; i++) {
        printf("File %d: ", i+1);
        scanf("%d", &file_size[i]);
    }

    worst_fit(blocksize, file_size, process, blocks_no, file_no);
    printf("------ the data -------\n");
    printf("File_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (int i = 0; i < file_no; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, file_size[i], block_no[i], block_used[i], fragment[i]);
    }

    return 0;
}

void worst_fit(int blocksize[], int file_size[], int process[], int blocks_no, int file_no) {
    int temp1, temp2, temp3, value;
    int worst_fit_index = -1;
    for (int i = 0; i < blocks_no; i++) {
        temporary[i] = blocksize[i];
        temporary1[i] = blocksize[i];
    }

    for (int i = 0; i < file_no; i++) {
        value = file_size[i];
        for (int j = 0; j < blocks_no; j++) {
            if (temporary[j] >= value) {
                if (worst_fit_index == -1 || temporary[j] > temporary[worst_fit_index]) {
                    worst_fit_index = j;
                }
            }
        }

        if (worst_fit_index != -1) {
            temp1 = temporary[worst_fit_index] - value;
            if (temp1>=0)
            {
            temporary[worst_fit_index] = temp1;
            temp2 = process[worst_fit_index];
            temp3 = value;
            fragment[i] = temp1;
            block_no[i] = process[worst_fit_index];
            block_used[i] = temporary1[worst_fit_index];
            }
            else{
                fragment[i] = 0;
                block_no[i] = 0;
                block_used[i] = 0;
            }
        }
    }
}
