#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows1, cols1;
    int m1, m2, m3, m4, m5, m6, m7, p1, p2, p3, p4;
    printf("Enter rows and columns for the matrix: ");
    scanf("%d %d", &rows1, &cols1);

    int **matrix1 = (int**) malloc (rows1 * sizeof(int*));
    int **matrix2 = (int**) malloc (rows1 * sizeof(int*));
    int **matrix3 = (int**) malloc (rows1 * sizeof(int*));

    for(int i = 0 ; i < rows1 ; i++) {
        matrix1[i] = (int*) malloc (cols1 * sizeof(int));
        if(matrix1[i] == NULL) {
            printf("Memory Allocation failed");
            return -1;
        }
    }

    for(int i = 0 ; i < rows1 ; i++) {
        matrix2[i] = (int*) malloc (cols1 * sizeof(int));
        if(matrix2[i] == NULL) {
            printf("Memory Allocation failed");
            return -1;
        }
    }

    for(int i = 0 ; i < rows1 ; i++) {
        matrix3[i] = (int*) malloc (cols1 * sizeof(int));
        if(matrix3[i] == NULL) {
            printf("Memory Allocation failed");
            return -1;
        }
    }

    printf("\nEnter the first matrix:");
    for(int i = 0 ; i < rows1 ; i++) {
        for(int j = 0 ; j < cols1 ; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the second matrix:");
    for(int i = 0 ; i < rows1 ; i++) {
        for(int j = 0 ; j < cols1 ; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    m1 = matrix1[0][0] * (matrix2[0][1] - matrix2[1][1]);
    m2 = (matrix1[0][0] + matrix1[0][1]) * matrix2[1][1];
    m3 = (matrix1[1][0] + matrix1[1][1]) * matrix2[0][0];
    m4 = matrix1[1][1] * (matrix2[1][0] - matrix2[0][0]);
    m5 = (matrix1[0][0] + matrix1[1][1]) * (matrix2[0][0] + matrix2[1][1]);
    m6 = (matrix1[0][1] - matrix1[1][1]) * (matrix2[1][0] + matrix2[1][1]);
    m7 = (matrix1[0][0] - matrix1[1][0]) * (matrix2[0][0] + matrix2[0][1]);

    matrix3[0][0] = m5 + m4 - m2 + m6;
    matrix3[0][1] = m1 + m2;
    matrix3[1][0] = m3 + m4;
    matrix3[1][1] = m1 + m5 - m3 - m7;

    printf("\nMatrix Multiplication:\n");
    for(int i = 0 ; i < rows1 ; i++) {
        for(int j = 0 ; j < cols1 ; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}