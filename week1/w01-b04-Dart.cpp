#include <iostream>
#include <cmath>

using namespace std;

main()
{
    int dart;
    int point = 0;
    int r = 10;
    cin >> dart;
    for(int i = 0;i < dart ;i++)
    {
        int x,y;
        cin >> x >> y;
        double position = pow((pow(x,2) + pow(y,2)),0.5);
        for(int j = 1;j <= (r/2);j++)
        {
            if(position <= j*2)
            {
                point = point + 5 - j + 1;
                break;
            }
        }
    }
    cout << point << endl;
}