#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int length;

void print_matrix(int **matrix) {
    for(int i=1 ; i<=length ; i++) {
        for(int j=1; j<=length ; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void matrix_multiplication(int *d) {
    int index, q, j;
    int **matrix = (int **) malloc ((length + 1) * sizeof(int *));
    int **k_matrix = (int **) malloc ((length + 1) * sizeof(int *));
    
    for(int i = 1; i <= length; i++) {
        matrix[i] = (int *) malloc ((length + 1) * sizeof(int));
        k_matrix[i] = (int *) malloc ((length + 1) * sizeof(int));
        if(matrix[i] == NULL || k_matrix[i] == NULL) {
            printf("\nMemory allocation not possible");
            exit(1);
        }
    }

    for(int i=1 ; i<=length ; i++) {
        matrix[i][i] = 0;
        k_matrix[i][i] = 0;
    }

    for(int L=2 ; L<=length ; L++) {
        for(int i=1; i<=length - L + 1; i++) {
            j = i + L - 1;
            matrix[i][j] = INT_MAX;
            for(int k=i ; k<j ; k++) {
                q = matrix[i][k] + matrix[k + 1][j] + (d[i-1] * d[k] * d[j]);
                if(q < matrix[i][j]) {
                    matrix[i][j] = q;
                    k_matrix[i][j] = k;
                }
            }
        }
    }

    print_matrix(matrix);
    print_matrix(k_matrix);

    for(int i = 1; i <= length; i++) {
        free(matrix[i]);
        free(k_matrix[i]);
    }
    free(matrix);
    free(k_matrix);
}

int main() {
    printf("Enter the number of matrices: ");
    scanf("%d", &length);

    int *d = (int *) malloc((length + 1) * sizeof(int));

    printf("\nEnter the d matrix: ");
    for(int i = 0; i <= length; i++)
        scanf("%d", &d[i]);

    matrix_multiplication(d);

    free(d);

    return 0;
}
