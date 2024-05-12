#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int V;
int solutionCount = 0;

void printSolution(int *color) {
    printf("\nSolution %d:\n Following are the assigned colors: \n", ++solutionCount);
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

/* A utility function to check if the current color assignment is safe for vertex v */
bool isSafe(int v, bool **graph, int *color, int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool **graph, int m, int *color, int v) {
    /* base case: If all vertices are assigned a color then print the solution */
    if (v == V) {
        printSolution(color);
        return true;
    }

    bool res = false;
    /* Consider this vertex v and try different colors */
    for(int c = 1; c <= m; c++) {
        /* Check if assignment of color c to v is fine*/
        if(isSafe(v, graph, color, c)) {
            color[v] = c;
            /* recur to assign colors to rest of the vertices */
            res = graphColoringUtil(graph, m, color, v + 1) || res;
            /* If assigning color c doesn't lead to a solution then remove it */
            color[v] = 0;
        }
    }

    return res;
}

/* This function solves the m Coloring problem using Backtracking. It mainly uses graphColoringUtil() to solve the problem. It returns false if the m colors cannot be assigned, otherwise return true and prints assignments of colors to all vertices. Please note that there may be more than one solutions, this function prints all the feasible solutions.*/
void graphColoring(bool **graph, int m) {
    // Initialize all color values as 0.
    // This initialization is needed
    // correct functioning of isSafe()
    int *color = (int *) malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if(!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist");
    }

    free(color);
}

int main() {
    int m;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    bool **graph = (bool **) malloc(V * sizeof(bool *));
    for (int i = 0; i < V; i++)
        graph[i] = (bool *) malloc(V * sizeof(bool));

    printf("\nEnter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            int input;
            scanf("%d", &input);
            graph[i][j] = input == 1 ? true : false;
        }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);

    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
