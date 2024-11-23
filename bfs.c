#include <stdio.h>

#define MAX_VERTICES 100
#define READY 1
#define WAITING 2
#define PROCESSED 3

int main() {
    int numVertices = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int status[MAX_VERTICES];

    // Define the graph
    graph[0][1] = graph[0][2] = 1;
    graph[1][3] = graph[1][4] = 1;
    graph[2][5] = 1;

    printf("BFS Traversal:\n");
    for (int i = 0; i < numVertices; i++) status[i] = READY;

    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = 0;
    status[0] = WAITING;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        status[currentVertex] = PROCESSED;

        for (int i = 0; i < numVertices; i++)
         {
            if (graph[currentVertex][i] && status[i] == READY)
            {
                queue[rear++] = i;
                status[i] = WAITING;
            }
        }
    }


    return 0;
}
