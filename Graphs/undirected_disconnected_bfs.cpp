#include <iostream>
#include <queue>
using namespace std;
void printBFS(int ** edges,int V,int sv)
{
    queue <int> pendingVertices;
    bool * visited= new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty())
    {
        int currentVertex= pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<V;i++)
        {
            if(edges[currentVertex][i]==1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
    delete[] visited;
}

int main() {
    int V, E;
    cin >> V >> E;
    int ** edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    printBFS(edges,V,0);

  return 0;
}
