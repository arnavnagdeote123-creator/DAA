#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
int distance[MAX], visited[MAX], parent[MAX];
    int i, j, count, nextnode, min;
    int path[MAX], k;

    for (i = 1; i <= n; i++) {
        distance[i] = INFINITY;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[startnode] = 0;

    for (count = 1; count <= n; count++) {
        min = INFINITY;
        nextnode = -1;

        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                nextnode = i;
            }
        }

        if (nextnode == -1)
            break;

        visited[nextnode] = 1;

} 
