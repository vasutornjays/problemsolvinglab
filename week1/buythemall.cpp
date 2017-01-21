#include <iostream>

using namespace std;

main()
{
    int a,b,c;
    int aprice,bprice,cprice;
    int n;
    a = 0 ,b = 0 ,c = 0;
    cin >> aprice >> bprice >> cprice;
    cin >> n;
    for(int i = 0 ; i < n;i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            a = a + aprice;
        }
        if(type == 2)
        {
            b = b + bprice;
        }
        if(type == 3)
        {
            c = c + cprice;
        }
    }
    if(a < b && a < c)
    {
        cout << a;
    }
    else if(b < a && b < c)
    {
        cout << b;
    }
    else if(c < b && c < a)
    {
        cout << c;
    }
    cout << endl;
}