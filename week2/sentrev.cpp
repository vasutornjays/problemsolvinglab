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
    while(charptr >= rear)
    {
        while(*charptr != '_' && charptr != rear)
        {
            charptr--;
        }
        if(charptr == rear)
        {
            cout << *charptr;
        }
        top = charptr;
        charptr++;
        while(*charptr != '_' && *charptr != '\0')
        {
            cout << *charptr;
            charptr++;
        }
        if(*top == '_')
        {
            cout << *top;
        }
        charptr = top;
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
