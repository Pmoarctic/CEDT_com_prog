#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 100000007

int solve1(int n)
{
    if(n==1)
    {
        cout << 3;
        return 0;
    }

    ll n00=1;
    ll n_0=2;
    ll n_1=2;
    ll n_2=2;

    for(ll i=3;i<=n;i++)
    {
        ll new00=0,new_0=0,new_1=0,new_2=0;
        new00 = (new00 + n00)%MOD;
        new00 = (new00 + n_0%MOD);

        new_0 = (new_0 + n_1)%MOD;
        new_0 = (new_0 + n_2)%MOD;

        new_1 = (new_1 + n00)%MOD;
        new_1 = ((2*new_1 + n_0+1)/2)%MOD;
        new_1 = (new_1 + n_1)%MOD;

        new_2 = (new_2 + n00)%MOD;
        new_2 = ((2*new_2 + n_0)/2)%MOD;
        new_2 = (new_2 + n_2)%MOD;

        n00 = new00%MOD;
        n_0 = new_0%MOD;
        n_1 = new_1%MOD;
        n_2 = new_2%MOD;
        //cout << n00 << "\n" << n_0 << "\n" << n_1 << "\n" << n_2 << "\n\n";
    }
    //cout << n00 << "\n" << n_0 << "\n" << n_1 << "\n" << n_2 << "\n\n";
    ll res = 0;
    res = (res + n00)%MOD;
    res = (res + n_0)%MOD;
    res = (res + n_1)%MOD;
    res = (res + n_2)%MOD;
    return res;
}

int solve2(int n)
{
    int dp[n+1]={};
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 15;
    dp[4] = 33;

    for(int i=5;i<=n;i++)
    {
        dp[i] = ((dp[i-1]*2)%MOD + dp[i-3])%MOD;
    }
    return dp[n];
}


int main()
{
    int n;
    //cin >> n;
    
    while(cin >> n)
    {
        cout << solve1(n) << "\n";
        cout << solve2(n) << "\n\n";
    }
    
}

/*
11321754
34206105
48000442
48000442

45527859
96000884
76425248
76425248
*/
