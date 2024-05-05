#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Dijkstra for getting all the paths
void dijkstra_algorithm_all_paths(int **graph, int src, int nodes) {
    int *dist = (int*) malloc (nodes * sizeof(int));
    int *parent = (int*) malloc (nodes * sizeof(int));
    int *visited = (int*) malloc (nodes * sizeof(int));

    for (int i = 0 ; i < nodes ; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(int i = 0 ; i < nodes - 1 ; i++) {
        int u, min_dist = INT_MAX;
        for(int v = 0 ; v < nodes ; v++) {
            if(!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        visited[u] = 1;
        for(int v = 0 ; v < nodes ; v++) {
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nVertex\tDistance\tPath\n");
    for(int i = 0 ; i < nodes ; i++) {
        printf("\n%d\t%d\t\t%d", i, dist[i], i);
        int j = i;
        while(parent[j] != -1) {
            printf(" <- %d", parent[j]);
            j = parent[j];
        }
        printf("\n");
    }

    free(dist);
    free(parent);
    free(visited);
}

//Dijkstra for getting only the shortest path from source to destination
void dijkstra_algorithm(int **graph, int src, int dest, int nodes) {
    int *dist = (int*) malloc (nodes * sizeof(int));
    int *parent = (int*) malloc (nodes * sizeof(int));
    int *visited = (int*) malloc (nodes * sizeof(int));

    for (int i = 0 ; i < nodes ; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(int i = 0 ; i < nodes - 1 ; i++) {
        int u, min_dist = INT_MAX;
        for(int v = 0 ; v < nodes ; v++) {
            if(!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        visited[u] = 1;
        for(int v = 0 ; v < nodes ; v++) {
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest Path from %d to %d: ", (src + 1), (dest + 1));
    int j = dest;
    printf("%d", dest);
    while(parent[j] != -1) {
        printf(" <- %d", parent[j]);
        j = parent[j];
    }

    free(dist);
    free(parent);
    free(visited);
}

int main() {
    int nodes, src, dest;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("\nEnter source and destination nodes: ");
    scanf("%d %d", &src, &dest);

    int **graph = (int**) malloc (nodes * sizeof(int*));
    for(int i = 0 ; i < nodes ; i++) {
        graph[i] = (int*) malloc (nodes * sizeof(int));
        if(graph[i] == NULL) {
            printf("Memory Allocation not possible");
            return -1;
        }
    }

    printf("\nEnter the Graph: \n");
    for(int i = 0 ; i < nodes ; i++) {
        for(int j = 0 ; j < nodes ; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    dijkstra_algorithm_all_paths(graph, src, nodes);
    dijkstra_algorithm(graph, src, dest, nodes);

    return 0;
}
