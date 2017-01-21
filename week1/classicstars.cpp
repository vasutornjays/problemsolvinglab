#include <iostream>

using namespace std;

main()
{
    int line;
    cin >> line;
    for(int i = 1 ; i <= line ; i++)
    {
        for(int j = 1 ; j <= line ; j++)
        {
            if(j <= line - i)
            {
                cout << ' ';
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }
}