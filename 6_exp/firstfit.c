#include <stdio.h>
#include <stdlib.h>

#define size 10

int blocksize[size];
int file_size[size];
int process[size];
int fragment[size];
int block_no[size];
int block_used[size];

void first_fit(int blocksize[], int file_size[], int process[], int blocks_no, int file_no);

int main() {
    int value, blocks_no, file_no;
    printf("\n\tRonit Satish Mehta 60009230207\n");
    printf("\n\t--------FIRST FIT CALCULATOR ---------\n");
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
        printf("Block %d: ", i);
        scanf("%d", &blocksize[i]);
    }
    printf("Enter the size of files:\n");
    for (int i = 0; i < file_no; i++) {
        printf("File %d: ", i);
        scanf("%d", &file_size[i]);
    }

    first_fit(blocksize, file_size, process, blocks_no, file_no);
    printf("------ the data -------\n");
    printf("File_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (int i = 0; i < file_no; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, file_size[i], block_no[i], block_used[i], fragment[i]); 
    }


    return 0;
}

void first_fit(int blocksize[], int file_size[], int process[], int blocks_no, int file_no) {
    int temp1, temp2, temp3, value;
    int temporary[size];
    for (int  i = 0; i < blocks_no; i++)
    {
        temporary[i] = blocksize[i];
    }
    
    for (int i = 0; i < file_no; i++) {
        value = file_size[i];
        int j = 0;
        while (j < blocks_no) {
            if (blocksize[j] >= value) {
                temp1 = blocksize[j] - value;
                blocksize[j] = temp1;
                temp2 = process[j];
                temp3 = value;
                fragment[i] = temp1;
                block_no[i] = process[j];  
                block_used[i] = temporary[j];      
                break;
            }
            j++;
        }
    }
}
