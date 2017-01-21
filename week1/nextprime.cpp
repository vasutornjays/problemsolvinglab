#include <iostream>

using namespace std;

bool check_prime (int p)
{
    if (p <= 1) {
        return false;
    }
  
    for(int i = 2;i<p;i++)
    {
        if(p%i == 0)
            {
            return false;
            }
    }

    return true;

}

int nextprime (int a)
{
    int prime_num = a + 1;
    while(!check_prime(prime_num))
    {
        prime_num++;
    }
    return prime_num;
}

main ()
{
    int input;
    cin >> input;
    cout << nextprime(input) << endl;
}