#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,l;
    int house[20];
    int count = 0; 
    cin >> n >> l;
    for(int i = 0; i < n ;i++)
    {
        cin >> house[i];
    }
    for(int i = 0; i < n ; i++)
    {
        for(int j = i+1;j < n;j++)
        {
            if(abs(house[i] - house[j]) <= l)
            {
                count++;
            }
        }
    }
    cout << count << endl;
}