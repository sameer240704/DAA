#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int vertices, edges, source;

void print_bellman_ford(int *dist) {
    printf("\nVertex\tDistance from Source\n");
    for(int i=0 ; i<vertices ; i++) 
        printf("%d\t%d\n", i, dist[i]);
}

void bellman_ford(int *src, int *dest, int *weight) {
    int *dist = (int *) malloc (vertices * sizeof(int));

    for(int i=0 ; i<vertices ; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    for(int i=1 ; i<=vertices ; i++) {
        for(int j=0 ; j<edges ; j++) {
            int u = src[j];
            int v = dest[j];
            int w = weight[j];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) 
                dist[v] = dist[u] + w;
        }
    }

    //For checking negative edge cycles
    for(int i=1 ; i<edges ; i++) {
        int u = src[i];
        int v = dest[i];
        int w = weight[i];
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Negative cycle detected");
            return;
        }
    }

    print_bellman_ford(dist);

    return;
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int *src = (int *) malloc (edges * sizeof(int));
    int *dest = (int *) malloc (edges * sizeof(int));
    int *weight = (int *) malloc (edges * sizeof(int));

    printf("Enter the edges and the respective weight: \n");
    for(int i=0 ; i<edges ; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &src[i], &dest[i], &weight[i]);
    }

    printf("Enter the source of the graph: ");
    scanf("%d", &source);

    bellman_ford(src, dest, weight);

    free(src);
    free(dest);
    free(weight);

    return 0;
}