#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int max;
    for(int i = 1 ; i <= a ; i++)
    {
        if(a%i == 0)
        {
            if(b%i == 0)
            {
                max = i;
            }
        }
    }
    return max;
}
main()
{
    int x,y;
    cin >> x >> y;
    int div = gcd(x,y);
    cout << x/div << "/" << y/div <<endl;
}