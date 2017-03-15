#include <iostream>

using namespace std;

char reve (char* sign)
{
    if(*sign == '}')
    {
        return '{';
    }
    else if(*sign == ']')
    {
        return '[';
    }
    else
    {
        return '(';
    }
}

int main()
{
    int round;
    cin >> round;
    bool result[25];
    for(int i = 0;i < round ; i++)
    {
        char input[110];
        char stack[110];
        char* stptr;
        stptr = stack;
        char* cptr;
        cin >> input;
        cptr = input;
        while(*cptr != '\0')
        {
            if(*cptr == '}' || *cptr == ']' || *cptr == ')')
            {
                if(*(stptr-1) == reve(cptr))
                {
                    stptr--;
                    *stptr = '\0';
                }
                else
                {
                    stptr++;
                    break;
                }
            }
            else
            {
                *stptr = *cptr;
                stptr++;
            }
            cptr++;
        }
        if(stptr == stack)
        {
            result[i] = true;
        }
        else
        {
            result[i] = false;
        }
    }
    for(int i = 0;i < round;i++)
    {
        if(result[i])
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}