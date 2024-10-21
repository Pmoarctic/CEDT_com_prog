#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    long long d = 2;

    cin >> n;

    if(n<2)
    {
        cout << "No prime factors for numbers less than 2.";
        return 0;
    }

    while(n>1)
    {
        if(d*d > n)
        {
            cout << n;
            break;
        }
        else if(n%d==0)
        {
            n/=d;
            cout <<  d << " ";
        }
        else
        {
            d++;
        }
    }
}