#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a;
    cin >> a;
    double L = 0, U = a;
    double x = (L+U)/2;
    while(abs(a-pow(10,x)) > max(a,pow(10,x))*pow(10,-10))
    {
        if(pow(10,x) > a)
        {
            U = x;
        }
        else if(pow(10,x) < a)
        {
            L = x;
        }

        x = (L+U)/2;
    }

    cout << x;
}