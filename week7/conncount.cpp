#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> adj[100000];
int deg[100000] = {};
bool visited[1000000] = {};

void dfs(int org)
{
    visited[org] = true;
    for(int i = 0;i < deg[org]; i++)
    {
        int dest = adj[org][i];
        if(!visited[dest])
        {
            dfs(dest);
        } 
    }
}

int main()
{
    int n,m;
    int component = 0;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m;i++)
    {
        int org, dest;
        scanf("%d %d", &org, &dest);
        org -= 1;
        dest -= 1;
        adj[org].push_back(dest);
        adj[dest].push_back(org);
        deg[org] += 1;
        deg[dest] += 1;
    }
    
    for(int i = 0; i < n ;i++)
    {
        if(!visited[i])
        {
            component += 1;
            dfs(i);
        }
    }
    printf("%d",component);
}