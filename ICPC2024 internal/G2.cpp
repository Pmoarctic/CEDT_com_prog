#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
//n,m,q <= 200,000
//h <= 1e9
int n,m,h,q;
int mx=0;
multiset<int> net;
vector<int> dis(1000005,0), res, res2(200005,0);

int main()
{
    cin >> n >> m >> h >> q;
    
    

    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        dis[x] = y;
        mx = max(mx, x);
    }

    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        net.insert(t);
    }

    res.pb(0);
    int cnt = 0;
    for(int i = 1; i <= mx; i++)
    {
        if(dis[i] != 0)
        {
            int delta = abs(dis[i] - h);
            auto it = net.lower_bound(delta);
            if(it != net.end())
            {
                net.erase(it);
                cnt++;
            }
        }
        res.pb(cnt);   
        if(net.empty())
        {
            break;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        auto it = lower_bound(all(res), i);
        if(it != res.end())
        {
            res2[i] = (it - res.begin());
        }
    }
    
    while(q--)
    {
        int k;
        cin >> k;
        if(k > cnt)
        {
            cout << "-1\n";
        }
        else
        {
            cout << res2[k] << "\n";
        }
    }

    return 0;
}
