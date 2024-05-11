#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int min(int *key, bool *visited, int length) {
    int min = INT_MAX, min_index;

    for(int i=0 ; i<length ; i++) {
        if(visited[i] == false && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

void print_graph(int *parent, int **graph, int length) {
    int sum = 0;

    printf("\nEdge\tWeight\n\n");
    for(int i=1 ; i<length ; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        sum += graph[i][parent[i]];
    }

    printf("\nThe minimum cost of the spanning tree is: %d", sum);
}

void prims_algorithm(int **graph, int length) {
    int *parent = (int *) malloc (length * sizeof(int));
    int *key = (int *) malloc (length * sizeof(int));
    bool *visited = (bool *) malloc (length * sizeof(bool));

    for(int i=0 ; i<length ; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count=0 ; count<length-1 ; count++) {
        int u = min(key, visited, length);

        visited[u] = true;

        for(int v=0 ; v<length ; v++) {
            if(graph[u][v] && visited[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    print_graph(parent, graph, length);
}

int main() {
    int length;
    printf("Enter the number of nodes in the graph:");
    scanf("%d", &length);

    int **graph = (int **) malloc (length * sizeof(int *));
    for (int i=0 ; i<length ; i++) {
        graph[i] = (int *) malloc (length * sizeof(int));
        if(graph[i] == NULL)
            printf("\nMemory Allocation is not possible");
    }

    printf("\nEnter the Graph: \n");
    for(int i=0 ; i<length ; i++) 
        for(int j=0 ; j<length ; j++) 
            scanf("%d", &graph[i][j]);

    prims_algorithm(graph, length);

    return 0;
}