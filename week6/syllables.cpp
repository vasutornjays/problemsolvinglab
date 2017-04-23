#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char c;
    for(int i = 0;i < n;i++)
    {
        char word[100];
        for (int i = 0; i < 100; i++)
        {
			word[i] = 0;
        }
        int count = 0;
        scanf("%s",&word);
        for(int i = 0;word[i] != '\0';i++)
        {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
			{
				while (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
				{
					i += 1;
				}
				count += 1;
			}
        }
        printf("%d\n",count);
    }
    return 0;
}