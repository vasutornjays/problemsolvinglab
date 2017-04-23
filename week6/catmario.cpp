#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    map<int,int> map;
    for(int i = 0;i < m ;i++)
    {
        int type,val;
        scanf("%d %d",&type,&val);
        if(map[type] == 0)
        {
            map[type] = val;
        }
        else if(val <= map[type])
        {
            map[type] = val;
        }
    }
    int totaltime = 0;
    for(int i = 0; i < n;i++)
    {
        totaltime += map[i+1];
    }
    printf("%d \n",totaltime);
    for(int i = 0; i < n;i++)
    {
        printf("%d %d\n", i+1, map[i+1]);
    }
}