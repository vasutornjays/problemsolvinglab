#include <iostream>

using namespace std;

void cycling(char* charptr)
{
    while(*charptr != 0)
    {   
        int value = *charptr;
        if(value > 118)
        {
            value =  value - 118 + 96 ; 
        }
        else
        {
            value = value + 4;
        }
        char resultchar = value;
        cout << resultchar;
        charptr++;
    }
}

int main()
{
    char input[110];
    char* cptr;
    cin.getline(input,110);
    cptr = input;
    cycling(cptr);
    return 0;
}
