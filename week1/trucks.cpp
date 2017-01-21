#include <iostream>

using namespace std;

main()
{
    int totalPack;
    int pack[100];
    int tmpweight;
    int truckinuse = 1;
    cin >> totalPack;
    for(int i = 0;i < totalPack;i++)
    {
        cin >> pack[i];
    }
    tmpweight = 0;
    for(int i = 0;i < totalPack;i++)
    {
        if(tmpweight + pack[i] > 1000)
        {
            truckinuse++; // next truck
            tmpweight = pack[i]; // load new package
        }
        else if(tmpweight + pack[i] == 1000 && i == totalPack - 1)
        {
            tmpweight = 0; // end
        }
        else if(tmpweight + pack[i] == 1000)
        {
            truckinuse++; // next truck
            tmpweight = 0; // new truck is empty
        }
        else
        {
            tmpweight = tmpweight + pack[i]; // load more package
        }
    }
    
    cout << truckinuse << endl;
}