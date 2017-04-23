#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,minsize;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y, r, min;
        scanf("%d %d %d", &x, &y, &r);
        if(y >= 0)
        {
            min = y - r; 
        }
        else
        {
            min = -(y + r);
        }
        if(i == 0)
        {
            minsize = min;
        }
        else if(min < minsize)
        {
            minsize = min;
        }
    }
    if(minsize <= 0)
    {
        minsize = -1;;
    }
    printf("%d\n",minsize);
}