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
vector<pii> vec;


int main()
{
    ////
    cin >> n >> m >> h >> q;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        vec.pb({a,b});
    }
    
    for(int i=0;i<m;i++)
    {
        int t;
        cin >> t;
        net.insert(t);
    }
    //

    vector<int> res;
    res.pb(0);
    for(int i=0;i<n;i++)
    {
        int x = vec[i].first;
        int y = vec[i].second;
        int delta = abs(y-h);
        if(net.lower_bound(delta) != net.end())
        {
            net.erase(net.lower_bound(delta));
            res.pb(x);
        }
        if(net.empty())
        {
            break;
        }
    }
    
    int mx = res.size();
    
    while(q--)
    {
        int k;
        cin >> k;
        if(k >= mx)
        {
            cout << "-1\n";
            continue;
        }
        cout << res[k] << "\n";
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