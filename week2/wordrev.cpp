#include <iostream>

using namespace std;

void wordreverse(char* charptr)
{
    while(*charptr != '\0')
    {
        char* base = charptr;
        while(*charptr != '_' && *charptr != '\0')
        {
            charptr++;
        }
        char* top = charptr;
        charptr--;
        while(charptr != base-1)
        {
            cout << *charptr;
            charptr--;
        }
        charptr = top;
        if(*charptr == '\0')
        {
            break;
        }
        cout << *charptr;
        charptr++;
    }
}

int main()
{
    char input[1100];
    char* cptr;
    cin.getline(input,1100);
    cptr = input;
    wordreverse(cptr);
    return 0;
}
