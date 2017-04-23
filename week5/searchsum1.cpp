#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    map<int,int> book_list;
    map<int,int>::iterator it;
    
    int n,k;
    int sum_price = 0;
    scanf("%d %d",&n,&k);
    it = book_list.begin();
    for(int i = 0; i < n;i++)
    {
        int price;
        scanf("%d",&price);
        sum_price += price;
        if(i == 0)
        {
            book_list[price] = i+1;
        }
        else
        {
            book_list[sum_price] = i+1;
        }
    }

    

    for(int i = 0;i < k;i++)
    {
        int money;
        scanf("%d",&money);
        it = book_list.find(money);
        if(it == book_list.end())
        {
            it = book_list.lower_bound(money);
            if(it->second >= n || it->second <= 0)
            {
                printf("%d\n",n);
            }
            else
            {
                printf("%d\n",it->second - 1);
            }
        }
        else
        {
            printf("%d\n",it->second);
        }
        // for(int j = 0; j < n;j++)
        // {
        //     it = book_list.lower_bound();
        //     if(it->second == money)
        //     {
        //         printf("%d\n",j+1);
        //         break;
        //     }
        //     else if(it->second > money)
        //     {
        //         printf("%d\n",j);
        //         break;
        //     }
        // }
    }
    return 0;

}