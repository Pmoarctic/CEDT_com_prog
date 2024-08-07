#include<bits/stdc++.h>
using namespace std;

long gcd(long a, long b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    double num,notrep,rep;
    cin >> num >> notrep >> rep;

    int n1 = ceil(log10(rep+1));
    int n2 = ceil(log10(notrep+1));
    
    cout << n1 << ' ' << log10(rep+1);
}