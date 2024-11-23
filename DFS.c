#include <stdio.h>

#define MAX_VERTICES 100
#define READY 1
#define WAITING 2
#define PROCESSED 3

int main() {
    int numVertices = 6; 
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; 
    int status[MAX_VERTICES], queue[MAX_VERTICES];
    int front = 0, rear = 0;


    graph[0][1] = graph[0][2] = 1;
    graph[1][3] = graph[1][4] = 1;
    graph[2][5] = 1;

    printf("\nDFS Traversal:\n");
    for (int i = 0; i < numVertices; i++) status[i] = READY;

    int stack[MAX_VERTICES], top = -1;
    stack[++top] = 0;

    while (top >= 0) {
        int currentVertex = stack[top--];

        if (status[currentVertex] == READY) {
            printf("%d ", currentVertex);
            status[currentVertex] = PROCESSED;

            for (int i = numVertices - 1; i >= 0; i--) {
                if (graph[currentVertex][i] && status[i] == READY) {
                    stack[++top] = i;
                }
            }
        }
    }

    return 0;
}
