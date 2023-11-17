 #include <stdio.h>


int isSafe(int processes, int resources, int max[10][10], int allocation[10][10], int available[10], int safeSequence[10]) {
    int need[10][10];
    int finish[10] = {0};
    int work[10];


    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }


    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    int count = 0;
    printf("< ");
    while (count < processes) {
        int found = 0;
        for (int p = 0; p < processes; p++) {

            if (!finish[p]) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }

                if (j == resources) {
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocation[p][k];
                    }
                    finish[p] = 1;
                    safeSequence[count] = p;
                    count++;
                    found = 1;

                    printf("P[%d] ", p);
                }
            }
        }

        if (!found) {
            printf(">\n");
            return 0;
        }
    }

    printf(">\n");
    return 1;
}

int main() {
    int processes, resources;
    int max[10][10], allocation[10][10], available[10];
    int safeSequence[10];
    printf("\nRonit satish mehta 60009230207");
    printf("\nEnter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the max instances of each resource:\n");
    for (int i = 0; i < resources; i++) {
        printf("a[%d]= ", i);
        scanf("%d", &available[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        printf("P[%d] ", i);
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the MAX matrix:\n");
    for (int i = 0; i < processes; i++) {
        printf("P[%d] ", i);
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }


    if (isSafe(processes, resources, max, allocation, available, safeSequence)) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is not in a safe state.\n");
        return 0;
    }

    return 0;
}

