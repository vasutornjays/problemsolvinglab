#include <iostream>

using namespace std;

void reverse(char* charptr)
{
    char* base = charptr;
    while(*charptr != 0)
    {   
        charptr++;
    }
    charptr--;
    while(charptr != base-1)
    {
        cout << *charptr;
        charptr--;
    }
}

int main()
{
    char input[1100];
    char* cptr;
    cin.getline(input,1100);
    cptr = input;
    reverse(cptr);
    return 0;
}
