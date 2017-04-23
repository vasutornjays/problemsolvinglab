#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int r, s, t;
    scanf("%d %d %d", &r, &s, &t);
    int n, minsize;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int jump;
        scanf("%d", &jump);
        if(jump < r)
        {
            printf("no\n");
        }
        else if(((jump - r) % (s + t)) > s)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
}