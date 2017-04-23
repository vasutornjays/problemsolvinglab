#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,m,num;
    char com;
    scanf("%d %d", &n, &m);
    getchar();
    char field[n][n];
    for(int i = 0;i < n;i++)
    {
        gets(field[i]);
    }
    for(int i = 0;i < m;i++)
    {
        scanf("%c %d", &com, &num);
        //printf("%c %d\n", com, num);
        num = num - 1;
        int start;
        getchar();
        if(com == 'L')
        {
            start = 0;
            for(int j = 0; j < n; j++)
            {
                if(field[num][start] == 'x')
                {
                    field[num][start] = '.';
                }
                else
                {
                    break;
                }
                start++;
            }
        }
        else if(com == 'R')
        {
             start = n-1;
            for(int j = 0; j < n; j++)
            {
                if(field[num][start] == 'x')
                {
                    field[num][start]= '.';
                }
                else
                {
                    break;
                }
                start--;
            }
        }
        else if(com == 'U')
        {
             start = 0;
            for(int j = 0; j < n; j++)
            {
                if(field[start][num] == 'x')
                {
                    field[start][num] = '.';
                }
                else
                {
                    break;
                }
                start++;
            }
        }
        else if(com == 'D')
        {
            start = n-1;
            for(int j = 0; j < n; j++)
            {
                if(field[start][num] == 'x')
                {
                    field[start][num]= '.';
                }
                else
                {
                    break;
                }
                start--;
            }
        }
        else if(com == 'A')
        {
            start = 0;
            for (int j = 0; j < n; j++)
				if (field[num][j] != '#')
                {
					field[num][j] = 'x';
                }
        }
        else if(com == 'B')
        {
            start = 0;
            for (int j = 0; j < n; j++)
				if (field[j][num] != '#')
                {
					field[j][num] = 'x';
                }
        }
    }
    for (int i = 0; i < n; i++)
    {
        {
            for (int j = 0; j < n; j++)
                printf("%c", field[i][j]);
            printf("\n");
        }
    }
}