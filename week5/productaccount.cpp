#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;



int main()
{
    map<int,int> product_list;
    map<int,int>::iterator it;
    it = product_list.begin();

    int n;
    scanf("%d",&n);
    for(int i = 0;i<n; i++)
    {
        int op,type,val;
        scanf("%d %d",&op,&type);
        if(op == 1)
        {
            scanf("%d",&val);
            product_list[type] += val;
        }
        else if(op == 2)
        {
            printf("%d\n",product_list[type]);
        }
        else if(op == 3)
        {
            scanf("%d",&val);
            if(val >= product_list[type])
            {
                printf("%d\n",product_list[type]);
                product_list[type] = 0;
            }
            else
            {
                printf("%d\n",val);
                product_list[type] = product_list[type] - val;
            }
        }
    }
    return 0;
}