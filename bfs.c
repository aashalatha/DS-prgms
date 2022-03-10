#include<stdio.h>
void bfs(int);
int graph[10][10],visited[10],n;

void bfs(int vertex)
{
    int i;
    printf("%d->",vertex);
    visited[vertex]=1;
    for(i=0;i<n;i++)
    {
        if(graph[vertex][i]==1 && !visited[i])
        {
            bfs(i);
        }
    }
}

int main()
{
    int i,j,count=0,v;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("Enter the starting vertex:");
    scanf("%d",&v);
    bfs(v);

    for(i=0;i<=n;i++)
    {
        if(visited[i])
        count++;
    }

    if(count==n)
    printf("\nGraph is connected");
    else
    printf("\nGraph is unconnected");
    return 0;
}