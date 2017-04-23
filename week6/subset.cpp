#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char set[20000];
    int count = 1;
    int i;
    gets(set);
    for(i = 0;set[i] != '\0' ; i++)
    {
        if(set[i] == ',')
        {
            count++;
        }
    }
    if(i == 2)
    {
        count = 0;
    }
    printf("%.0f\n", pow(2,count));
}