#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int V;

void printSolution(int path[]);

/* A utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle constructed so far (stored in 'path[]') */
bool isSafe(int v, bool **graph, int *path, int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

/* A recursive utility function to solve Hamiltonian cycle problem */
bool hamCycleUtil(bool **graph, int *path, int pos, int *count) {
    // Base case: If all vertices are included in the Hamiltonian cycle
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            (*count)++;
            printf("Hamiltonian Cycle %d: \n", *count);
            printSolution(path);
            return true;
        } else
            return false;
    }

    // Try different vertices as the next candidate in Hamiltonian Cycle
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            hamCycleUtil(graph, path, pos + 1, count);

            // If adding vertex v doesn't lead to a solution, then remove it
            path[pos] = -1;
        }
    }

    // If no vertex can be added to the Hamiltonian Cycle constructed so far, then return false
    return false;
}

/* This function solves the Hamiltonian Cycle problem using Backtracking */
void hamCycle(bool **graph) {
    int *path = (int *) malloc (V * sizeof(int));

    for (int i = 0; i < V; i++)
        path[i] = -1;

    int count = 0;

    // Let's put vertex 0 as the first vertex in the path. If there's a Hamiltonian Cycle, it'll start from vertex 0
    path[0] = 0;
    hamCycleUtil(graph, path, 1, &count);

    if (count == 0) 
        printf("No Hamiltonian Cycle exists\n");

    free(path);
}

// A utility function to print the solution
void printSolution(int path[]) {
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf(" %d ", path[0]);
    printf("\n");
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    bool **graph = (bool **) malloc (V * sizeof(bool*));
    for(int i = 0; i < V; i++)
        graph[i] = (bool *) malloc (V * sizeof(bool));

    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++) {
            int input;
            scanf("%d", &input);
            graph[i][j] = input == 1 ? true : false;
        }
    
    hamCycle(graph);

    for(int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}

