#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;



int main()
{
    map<int,int> like_map;
    map<int,int>::iterator it;
    it = like_map.begin();

    int n,last;
    int max = 0;
    scanf("%d",&n);
    for(int i = 0;i<n; i++)
    {
        int like;
        scanf("%d",&like);
        like_map[like] += 1;
        if(like_map[like] >= max)
        {
            max = like_map[like];
            last = like;
        }
        printf("%d\n",last);
    }
    return 0;
}