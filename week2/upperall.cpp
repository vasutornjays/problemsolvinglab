#include <iostream>

using namespace std;

void upperall(char* charptr)
{
    while(*charptr != 0)
    {   
        int value = *charptr;
        if(value >= 97 && value <= 122)
        {
            value =  value - 32;
        }
        else
        {
            value = value;
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
    upperall(cptr);
    return 0;
}
