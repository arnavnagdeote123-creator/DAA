#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void kruskalMST(int **cost, int V) {

	int *parent = (int *)malloc(V * sizeof(int));
	for (int i = 0; i < V; i++) {
	parent[i] = i;
	}
	int minCost = 0;
	int edgeCount = 0;
	while (edgeCount < V - 1) {
		int minWeight = 9999;
		int u = -1, v = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (cost[i][j] < minWeight && i != j) {
					minWeight = cost[i][j];
					u = i;
					v = j;
				}
			}
		}
		if (u == -1 || v == -1) break;
		int root_u = u;
		while (parent[root_u] != root_u) {
			root_u = parent[root_u];
		}
		int root_v = v;
		while (parent[root_v] != root_v) {
			root_v = parent[root_v];
		}
		if (root_u != root_v) {
			printf("Edge %d:(%d, %d) cost:%d\n", edgeCount, u, v, minWeight);
			minCost += minWeight;
			edgeCount++;
			parent[root_u] = root_v;
		}
		cost[u][v] = 9999;
		cost[v][u] = 9999;
	}

	printf("Minimum cost= %d\n", minCost);
	free(parent);
}

int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
