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

int n,m,h,q;
int mx=0;
multiset<int> net;
vector<int> dis(2000000,0),res,res2(2000000,0);


int main()
{
    ////
    cin >> n >> m >> h >> q;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        dis[x] = y;

        mx = max(mx,x);
    }
    for(int i=0;i<m;i++)
    {
        int t;
        cin >> t;
        net.insert(t);
    }
    //

    res.pb(0);
    int cnt=0;
    for(int i=1;i<=mx;i++)
    {
        if(dis[i]!=0)
        {
            int delta = abs(dis[i]-h);
            if(net.lower_bound(delta) != net.end())
            {
                net.erase(net.lower_bound(delta));
                cnt++;
            }
        }
        res.pb(cnt);   
        if(net.empty())
        {
            break;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(lower_bound(all(res),i) == res.end())
        {
            break;
        }
        res2[i] = (lower_bound(all(res),i)-res.begin());
    }
    
    while(q--)
    {
        int k;
        cin >> k;
        if(k > cnt)
        {
            cout << "-1\n";
            continue;
        }
        cout << res2[k] << "\n";
    }

    return 0;
}
/*
10 5 5 3
2 10
4 10
6 10
8 10
10 10
12 10
14 10
16 10
18 10
20 10
5 5 5 5 5
1
2
3
*/
/*
10 5 5 3
2 10
4 10
6 10
8 10
10 10
12 10
14 10
16 10
18 10
20 10
1 1 1 1 1
1
2
3
*/