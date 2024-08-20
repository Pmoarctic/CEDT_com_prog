#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dig(ll n)
{
    ll cnt=0;
    while(n!=0)
    {
        cnt++;
        n/=10;
    }
    return cnt;
    /*
    if(n==0)return 1;

    return ceil(log10(n+1));
    */
}

ll power(ll a,ll b)
{
    ll tmp=1;
    for(int i=0;i<b;i++)
    {
        tmp *= a;
    }
    return tmp;
}

int main()
{
    ll st,ed;
    cin >> st >> ed;
    ll res1=0,res2=0,res3=0;

    //cout << dig(ed) << endl;


    while(ed!=0)
    {
    ll d = dig(ed);
    ll base = power(10,d-1);
    ll n = ed-base+1;
    res1 += n*d;

    
    ed = base-1;

    }

    if(st==0)
    {
        cout << res1+1;
        return 0;
    }

    ll cnt;
    st--;
    while(st!=0)
    {
    ll d = dig(st);
    ll base = power(10,d-1);
    ll n = st-base+1;
    res2 += n*d;

    st = base-1;
    cnt = d;
    }

    cout << res1-res2 + cnt - 1;
}
//0 1 2 3 4 5 6 7 8 9 10

/*
1-9; = 9
10-99; = 180
100-999; = 2700
1000-3825; = 
*/