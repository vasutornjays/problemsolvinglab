#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char name[4][50];
    for(int i = 0;i < 4;i++)
    {
        gets(name[i]);
    }
    int score [4][4];
    for(int i = 0;i < 4;i++)
    {
            scanf("%d %d %d %d",&score[i][0],&score[i][1],&score[i][2],&score[i][3]);
    }
    int point[4] = {0,0,0,0};
    int gd[4] = {0,0,0,0};
    int goal[4] = {0,0,0,0};
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(i == j)
            {
                continue;
            }
            gd[i] += (score[i][j] - score[j][i]);
            // printf("%s vs %s = %d \n",name[i],name[j],gd[i]);
            goal[i] += score[i][j];
            if(score[i][j] > score[j][i])
            {
                point[i] += 3;
            }
            else if(score[i][j] == score[j][i])
            {
                point[i] += 1;
            }
        }
    }
    int rank[4] = {0,0,0,0};
    for(int i = 0;i < 4;i++)
    {
        int temp_rank = 3;
        for(int j = 0;j < 4;j++)
        {
            if(i == j)
            {
                continue;
            }
            if(point[i] > point[j])
            {
                temp_rank--;
            }
            else if(point[i] == point[j])
            {
                if(gd[i] > gd[j])
                {
                    temp_rank--;
                }
                else if(gd[i] == gd[j])
                {
                    if(goal[i] > goal[j])
                    {
                        temp_rank--;
                    }
                }
            }
        }
        rank[temp_rank] = i;
    }
    for(int i = 0;i < 4;i++)
    {
        printf("%s %d\n",name[rank[i]],point[rank[i]]);
    }
}