#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);
    int val[2000];
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&val[i]);
        if(val[i] >= max)
        {
            max = val[i];
        }
    }

    if(max < a)
    {
        max = a;
    }

    int size;
    int mindf = 0;
    for(int i = max; i <= b; i++)
    {   
        int df = 0;
        int tmp = 0;
        for(int j = 0; j < n ; j++)
        {
            if((tmp + val[j]) <= i)
            {
                tmp += val[j];
            }
            else
            {
                df += (i - tmp);
                tmp = val[j];
            }
        }
        df += (i - tmp);
        if(i == max)
        {
            size = i;
            mindf = df;
        }
        else if(df < mindf)
        {
            size = i;
            mindf = df;
        }
        //printf("%d %d\n", i, df);
    }
    printf("%d\n",size);
}