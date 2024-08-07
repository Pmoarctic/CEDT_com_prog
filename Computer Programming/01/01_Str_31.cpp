#include<bits/stdc++.h>
using namespace std;

long gcd(long a, long b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    string nums,notreps,reps;
    cin >> nums >> notreps >> reps;
    
    long dnotrep = notreps.size();
    long drep = reps.size();
    //long dnotrep = floor(log10(notrep) + 1);
    //long drep = floor(log10(notrep) + 1);
    long notrep = stol(notreps);
    long rep = stol(reps);
    long num = stol(nums);

    long total = notrep*pow(10,drep)+rep;

    long up = total - notrep;
    
    long down = (pow(10,dnotrep+drep) - pow(10,dnotrep));
    
    up = num*down + up;

    long tmp = gcd(up,down);

    cout << up/tmp << " / " << down/tmp;
}