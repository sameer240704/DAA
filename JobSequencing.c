#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_schedule(int *schedule, int jobs) {
    for(int i=0 ; i<jobs ; i++) {
        if(schedule[i] != -1)
            printf("J%d -> ", schedule[i]);
    }
}

void job_sequencing(int *deadline, int *index, int jobs) {
    int *schedule = (int *) malloc (jobs * sizeof(int));

    for(int i=0 ; i<jobs ; i++) 
        schedule[i] = -1;

    for(int i=0 ; i<jobs ; i++) {
        bool set = false;
        int j = deadline[i];
        while(j > 0 && schedule[j] != -1) {
            j--;
        }
        if(j > 0) {
            schedule[j] = index[i];
        }
    }

    print_schedule(schedule, jobs);

    free(schedule);
}

int main() {
    int jobs, temp;

    printf("Enter the number of jobs: ");
    scanf("%d", &jobs);

    int *deadline = (int *) malloc (jobs * sizeof(int));
    int *profit = (int *) malloc (jobs * sizeof(int));
    int *index = (int *) malloc (jobs * sizeof(int));

    for(int i=0 ; i<jobs ; i++) {
        printf("Enter deadline and profit for J%d: ", i+1);
        scanf("%d %d", &deadline[i], &profit[i]);
        index[i] = i+1;
    }

    for(int i=0 ; i<jobs ; i++) {
        for(int j=0 ; j<jobs-i-1 ; j++) {
            if(profit[j] < profit[j+1]) {
                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = temp;

                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
    }

    job_sequencing(deadline, index, jobs);

    free(profit);
    free(deadline);
    free(index);

    return 0;
}