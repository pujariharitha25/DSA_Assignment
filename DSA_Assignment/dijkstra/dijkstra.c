#include <stdio.h>

#define INF 9999

int main()
{
    int n, graph[20][20], dist[20], visited[20] = {0};
    int source, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(int i = 0; i < n; i++)
        dist[i] = graph[source][i];

    dist[source] = 0;
    visited[source] = 1;

    for(int count = 1; count < n; count++)
    {
        min = INF;
        u = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && graph[u][i] != 0 &&
               dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", source);

    for(int i = 0; i < n; i++)
        printf("Vertex %d : %d\n", i, dist[i]);

    return 0;
}