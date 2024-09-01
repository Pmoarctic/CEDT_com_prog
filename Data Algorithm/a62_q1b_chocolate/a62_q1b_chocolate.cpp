#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
#define unmap unordered_map
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

const int MOD = 1e6 + 3;

int main()
{
    int n,k;
    cin >> n >> k;
    vi v;
    while(k--)
    {
        int t;
        cin >> t;
        v.pb(t);
    }

    //init
    vector<int> dp(n+1,0);
    dp[0]=1;
    //
    for(int i=1;i<=n;i++)
    {
        for(int s:v)
        {
            if(i-s >= 0)
            {
                dp[i] = (dp[i] + dp[i-s])%MOD;
            }
        }
    }
    cout << dp[n];

    return 0;
}

// dp bottom up