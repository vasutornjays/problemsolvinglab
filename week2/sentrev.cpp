#include <iostream>

using namespace std;

void sentreverse(char* charptr)
{
    char* rear = charptr;
    char* top;
    while(*charptr != '\0')
    {
        charptr++;
    }
    top = charptr;
    while(charptr >= rear-1)
    {
        while(*charptr != '_' && charptr != rear-1)
        {
            charptr--;
        }
        top = charptr;
        charptr++;
        while(*charptr != '_' && *charptr != '\0')
        {
            cout << *charptr;
            charptr++;
        }
        charptr = top;
        if(charptr >= rear-1)
        {
            cout << *charptr;
        }
        charptr--;
    }
}

int main()
{
    char input[1100];
    char* cptr;
    cin.getline(input,1100);
    cptr = input;
    sentreverse(cptr);
    return 0;
}
