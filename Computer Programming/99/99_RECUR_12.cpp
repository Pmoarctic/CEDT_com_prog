#include<bits/stdc++.h>
using namespace std;

long a,k,m;
long recur(int k)
{
    if(k==0)
    {
        return 1;
    }
    else if(k%2==0)
    {
        return (recur(k/2)*recur(k/2))%m;
    }
    else if(k%2==1)
    {
        return (a*recur(k/2)*recur(k/2))%m;
    }
}

int main()
{

    cin >> a >> k >> m;

    cout << recur(k);
}