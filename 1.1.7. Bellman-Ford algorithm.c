#include <stdio.h>
#include <limits.h>

#define MAX 1000
#define INF 1000000000

typedef struct {
    int u;
    int v;
    int w;
} Edge;

Edge edges[MAX * MAX];
int dist[MAX + 1];
int parent[MAX + 1];

void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }

    printPath(parent[v]);
    printf("->%d", v);
}

int main() {
    int V, E;
    int src;

    scanf("%d", &V);
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].u,
}
