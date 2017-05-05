#include <stdio.h>
#include <iostream>

int set[100000];
int size[100000] = {};

int root(int i)
{
    while (i != set[i])
    {
        set[i] = set[set[i]];
        i = set[i];
    }
    return i;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    getchar();
    for(int i = 0; i < n; i++)
    {
        set[i] = i;
    }
    for(int i = 0; i < q; i++)
    {
        char op;
        int x, y;
        scanf("%c %d %d", &op, &x, &y);
        getchar();
        x -= 1;
        y -= 1;
        if(op == 'c')
        {
            int a = root(x);
            int b = root(y);
            if(size[a] < size[b])
            {
                set[a] = b;
                size[b] += size[a]; 
            }
            else
            {
                set[b] = a;
                size[a] += size[b];
            }
        }
        else if(op == 'q')
        {
            bool check = root(x) == root(y);
            if(check)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        // for(int i = 0; i < n; i++)
        // {
        //     printf("%d ",set[i]);
        // }
        // printf("\n");
    }
    return 0;
}