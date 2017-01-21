#include <iostream>

using namespace std;

main()
{
    int noGift;
    int total = 0;
    cin >> noGift;
    for(int i = 0; i < noGift ; i++)
    {
        int giftvalue;
        cin >> giftvalue;
        if(giftvalue > 0)
        {
            total = total + giftvalue;
        }
    }
    cout << total << endl;
}