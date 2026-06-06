#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites,
               int prerequisitesSize,
               int* prerequisitesColSize)
{
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++)
    {
        graph[i] = (int*)malloc(prerequisitesSize * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++)
    {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        graph[b][graphSize[b]++] = a;
        indegree[a]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));

    int front = 0;
    int rear = 0;

    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear)
    {
        int node = queue[front++];
        count++;

        for (int i = 0; i < graphSize[node]; i++)
        {
            int next = graph[node][i];

            indegree[next]--;

            if (indegree[next] == 0)
            {
                queue[rear++] = next;
            }
        }
    }

    return (count == numCourses);
}