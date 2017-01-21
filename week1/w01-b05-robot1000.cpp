#include <stdio.h>

main()
{
    char input[120];
    char *Cptr;
    int x = 0;
    int y = 0;

    scanf("%s",input);
    Cptr = input;

    while(*Cptr != '\0')
    {
        if(*Cptr == 'N')
        {
            y++;
        }
        else if(*Cptr == 'E')
        {
            x++;
        }
        else if(*Cptr == 'W')
        {
            x--;
        }
        else if(*Cptr == 'S')
        {
            y--;
        }
        else if(*Cptr == 'Z')
        {
            x = 0;
            y = 0;
        }
        
        Cptr++;
    }

    printf("%d %d \n",x,y);
  
}