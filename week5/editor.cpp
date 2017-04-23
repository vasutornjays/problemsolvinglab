#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    vector<string> sentence;
    vector<string>::iterator it;

    it = sentence.begin();

    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        char op;
        char word[100];
        scanf(" %c",&op);
        if(op == 'i')
        {
            scanf("%s",word);
            it = sentence.insert(it, word);
            it++;
        }
        else if(op == 'l')
        {
            if(it != sentence.begin())
            {
                it--;
            }
        }
        else if(op == 'r')
        {
            if(it != sentence.end())
            {
                it++;
            }
        }
        else if(op == 'b')
        {
            if(it != sentence.begin())
            {
                it--;
                it = sentence.erase(it);
            }
        }
        else if(op == 'd')
        {
            if(it != sentence.end())
            {
                it = sentence.erase(it);
            }
        }
    }
        for (vector<string>::iterator i=sentence.begin(); i != sentence.end();i++)
        {
            cout << *i << ' ';
        }
    cout << '\n';
    return 0;
}