#include<stdio.h>
#include<string.h>
#define N 50

int dfs (int source, int destination, int v, int graph[][N], int visited[]) {
    int fl = 0;
    if (source == destination) fl = 1;

    visited[source] = 1;

    for (int i = 0; i < v; i++) {
        if (graph[source][i] == 1 && (!visited[i]))
            fl = dfs(i, destination, v, graph, visited);
    }
    return fl;
}

int main() {

    int n, source, destination, graph[N][N], visited[N], fl;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Input adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
    }

    printf("Enter source node: ");
    scanf("%d", &source);

    printf("Enter destination node: ");
    scanf("%d", &destination);
    memset(visited, 0, n * sizeof(visited[0]));
    
    fl = dfs(source-1, destination-1, n, graph, visited);

    if (fl) printf("Yes\n");
    else printf("No\n");

    return 0;
}