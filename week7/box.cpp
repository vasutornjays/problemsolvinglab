#include <iostream>
#include <stdio.h>

using namespace std;

char map[30][30] = {};
bool visited[30][30] = {};
int n, m;
bool check = false;

void search(int posx, int posy)
{
    if(posx + 1 < n && posy + 1 < m && map[posx][posy] == '.' && map[posx + 1][posy] == '.' && map[posx][posy+1] == '.' && map[posx + 1][posy + 1] == '.')
    {
        if(posx == n - 2)
        {
            check = true;
        }

        visited[posx][posy] = true;

        if(posy - 1 >= 0 && !visited[posx][posy - 1])
        {
            search(posx, posy - 1);
        }
        if(posy + 1 < m && !visited[posx][posy + 1])
        {
            search(posx, posy + 1);
        }
        if(posx + 1 < n && !visited[posx + 1][posy])
        {
            search(posx + 1, posy);
        }
        if(posx - 1 >= 0 && !visited[posx - 1][posy])
        {
            search(posx - 1, posy);
        }
        
        
    }
}

int main()
{
    scanf("%d %d",&n, &m);
    getchar();
    for(int i = 0;i < n;i++)
    {
        gets(map[i]);
    }
    for(int i = 0; i < m; i++)
    {
        if(map[0][i] == '.' && !visited[0][i])
        {    
            search(0,i);
            if(check == true)
            {
                break;
            }
            for(int p = 1; p < n;p++)
            {
                for(int j = 0; j < m ;j++)
                {
                    visited[p][j] = false;
                }
            }
        }
    }
    printf("%s\n", check ? "yes" : "no");
    return 0;
}