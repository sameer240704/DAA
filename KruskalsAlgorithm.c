// Not complete yet

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void kruskals_algorithm(int **graph, int length) {
    
}

int main() {
    int length;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &length);

    int **graph = (int **) malloc (length * sizeof(int *));
    for(int i=0 ; i<length ; i++) {
        graph[i] = (int *) malloc (length * sizeof(int));
        if(graph[i] == NULL)
            printf("\nMemory Allocation is not possible");
    }

    for(int i=0 ; i<length ; i++)
        for(int j=0 ; i<length ; j++)
            scanf("%d", &graph[i][j]);

    kruskals_algorithm(graph, length);

    return 0;
}