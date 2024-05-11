// All Pair Shortest Path

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int length;

int min(int a, int b) {
    return a > b ? b : a;
}

void print_solution(int **matrix) {
    printf("\nSolution: \n");
    for(int i=0 ; i<length ; i++) {
        for(int j=0 ; j<length ; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void flloyd_algorithm(int **matrix) {
    for(int k=0 ; k<length ; k++) 
        for(int i=0 ; i<length ; i++)
            for(int j=0 ; j<length ; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    print_solution(matrix);
}

int main() {
    printf("Enter the length of the matrix: ");
    scanf("%d", &length);

    int **matrix = (int **) malloc (length * sizeof(int *));
    for(int i=0 ; i<length ; i++) {
        matrix[i] = (int *) malloc (length * sizeof(int));
        if(matrix[i] == NULL) {
            printf("Memory allocation not possible");
            exit(1);
        }
    }

    printf("\nEnter the matrix: \n");
    for(int i=0 ; i<length ; i++) {
        for(int j=0 ; j<length ; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == -1) 
                matrix[i][j] = 10000;
        }
    }

    flloyd_algorithm(matrix);

    free(matrix);

    return 0;
}