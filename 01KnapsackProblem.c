#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int total_weight, n;
    printf("Enter the total elements: ");
    scanf("%d", &n);

    printf("\nEnter the total weight: ");
    scanf("%d", &total_weight);

    int *weight = (int*) malloc (n * sizeof(int));
    int *profit = (int*) malloc (n * sizeof(int));

    printf("\nEnter the weight matrix:\n");
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &weight[i]);

    printf("\nEnter the profit matrix:\n");
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &profit[i]);  

    int **result_matrix = (int**) malloc ((n + 1) * sizeof(int*));
    for(int i = 0 ; i <= n ; i++) {
        result_matrix[i] = (int*) malloc ((total_weight + 1) * sizeof(int));
        if(result_matrix[i] == NULL) {
            printf("\nMemory Allocation is not possible");
            return -1;
        }
    }

    for(int w = 0 ; w <= total_weight ; w++)
        result_matrix[0][w] = 0;

    for(int i = 0 ; i <= n ; i++)
        result_matrix[i][0] = 0;

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= total_weight ; j++) {
            if(weight[i-1] <= j)
                result_matrix[i][j] = max(result_matrix[i-1][j], profit[i-1] + result_matrix[i-1][j-weight[i-1]]);
            else 
                result_matrix[i][j] = result_matrix[i-1][j];
        }
    }

    printf("Maximum Value: %d\n", result_matrix[n][total_weight]);

    for(int i = 0; i <= n; i++) {
        free(result_matrix[i]);
    }
    free(result_matrix);
    free(weight);
    free(profit);

    return 0;
}
