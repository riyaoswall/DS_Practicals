/*
Name: Riya
Roll no: CO2105
Title: Social network connectivity using adjacency matrix.
*/

#include<stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start)
{
  int queue[MAX];
  int front=0,rear=0;
  int i,v;
  
  for(i=1;i<=n;i++)
  {
    visited[i]=0;
  }
  
  visited[start]=1;
  queue[rear++]=start;
  
  printf("BFS Traversal: ");
  
  while(front < rear)
  {
    v=queue[front++];
    printf("%d",v);
    
    for(i=1;i<=n;i++)
    {
      if(graph[v][i] == 1 && visited[i]==0)
      {
        visited[i]=1;
        queue[rear++]=i;
      }
    }
  }
  printf("\n");
}

void DFS(int v)
{
  int i;
  visited[v]=1;
  printf("%d",v);
  
  for(i=1;i<=n;i++)
  {
    if(graph[v][i]==1 && visited[i]==0)
    {
      DFS(i);
    }
  }
}

int main()
{
  int edges,u,v,i,start;
  
  for(i=0;i<MAX;i++)
  {
    for(int j=0;j<MAX;j++)
    {
      graph[i][j]=0;
    }
  }
  
  printf("Enter number of users: ");
  scanf("%d",&n);
  
  printf("Enter number of connections: ");
  scanf("%d",&edges);
  
  printf("Enter connections(user1,user2):\n");
  
  for(i=0;i<edges;i++)
  {
    scanf("%d %d",&u,&v);
    
    graph[u][v]=1;
    graph[v][u]=1;
  }
  
  printf("Enter starting user: ");
  scanf("%d",&start);
  
  BFS(start);
  
  for(i=1;i<=n;i++)
  {
    visited[i]=0;
  }
  
  printf("DFS Travesal:");
  DFS(start);
  printf("\n");
  
  return 0;
}
