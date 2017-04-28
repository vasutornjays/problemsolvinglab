#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100000];
int deg[100000] = {};

bool isBipartite(int n)
{
    int colorArr[n];
    for(int i = 1; i < n; i++) // all node to red
    {
        colorArr[i] = -1;
    }

    colorArr[0] = 1;

    queue <int> q;
    q.push(0);

    while(!q.empty())
    {
        int org = q.front();
        q.pop();

        for(int i = 0;i < deg[org]; i++)
        {
            int dest = adj[org][i];
            if(colorArr[dest] == -1)
            {
                colorArr[dest] = 1 - colorArr[org];
                q.push(dest);
            }
            else if (colorArr[org] == colorArr[dest])
            {
                return false;
            }
        }
    }

    return true;

}

int main()
{
    int ng;
    scanf("%d", &ng);
    for(int r = 0; r < ng;r++)
    {
        int n,m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n ; i++)
        {
            deg[i] = 0;
            adj[i].clear();
        }

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
        printf("%s\n", isBipartite(n) ? "yes" : "no");
    }
}