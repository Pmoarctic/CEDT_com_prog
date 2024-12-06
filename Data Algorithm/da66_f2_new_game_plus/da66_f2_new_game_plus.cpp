#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (long long)100000007
ll mp[510][510] = {};
ll dp[510][510][3] = {};
int main()
{
    ll n,m;
    cin >> n >> m;
    
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin >> mp[i][j];
            if(mp[i][j]==0 && j==1)
            {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 1;
            }
        }
    }

    long long res=0;
    for(ll c=2;c<=m;c++)
    {
        for(ll r=1;r<=n;r++)
        {
            if(mp[r][c]==1)continue;

            dp[r][c][0] = (dp[r][c-1][1] + dp[r+1][c-1][2])%MOD;
            dp[r][c][1] = (dp[r-1][c-1][0] + dp[r+1][c-1][2])%MOD;
            dp[r][c][2] = (dp[r-1][c-1][0] + dp[r][c-1][1])%MOD;
            if(c==m)
            {
                res += (dp[r-1][c-1][0] + dp[r][c-1][1] + dp[r+1][c-1][2])%MOD;
                res %= MOD;
            }
        }
    }

    cout << res;
}